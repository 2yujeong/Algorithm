/*
문제 출처 : https://www.acmicpc.net/problem/1202 (백준 온라인 저지)

N개의 보석의 무게와 가격이 주어질 때 가방 K개를 가지고 훔칠 수 있는 보석의 최대 가치를 구하는 문제.
각 가방에 담을 수 있는 보석의 최대 무게는 Ci이며 가방에는 최대 한 개의 보석만 담을 수 있다.

처음에는 우선순위 큐를 이용하여 다음과 같이 구현했다.
 1. 보석을 가격 기준으로 내림차순
 2. 가방 용량을 기준으로 내림차순
 3. 보석의 top과 가방의 top을 비교해가며 훔칠 수 있는 최대 가치 계산
하지만 이렇게 구현하면 무게는 크고 가치는 작은 보석을 추가로 담는 경우를 빠트릴 수 있어 틀렸습니다가 뜬다.
예를 들어 보석 (5, 10), (1, 20)이 주어지고 가방 1, 2의 용량이 1, 5라면 가방 1에 (1, 20), 가방 2에 (5, 10)을 넣어 총 30의 가치를 챙길 수 있지만
위에서 구현한 로직으로는 가방 2에만 (1, 20)이 담기고 알고리즘이 끝나게 된다.
이러한 경우를 빠트리지 않기 위해서 다음과 같이 구현하였다.
 1. 보석을 무게 기준으로 오름차순
 2. 가방 용량을 기준으로 오름차순
 3. 첫 번째 가방부터, 가방 i에 담을 수 있는 모든 보석들의 가치를 우선순위 큐에 넣는다.
 4. 우선순위 큐에 담긴 가치들 중 가장 높은 가치(top)를 정답에 더하고 pop해준다.

시간복잡도는 O(n + k)
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int> > jewel;
	priority_queue<int, vector<int>, greater<int>> bag; // 오름차순 정렬

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;

		jewel.push_back({ m, v });
	}

	sort(jewel.begin(), jewel.end()); // 무게를 기준으로 오름차순 정렬

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;

		bag.push(c);
	}

	long long max_val = 0;

	// 가방 용량을 기준으로 오름차순 정렬했기 때문에 i번째 가방에 담을 수 있는 보석들은 i + 1번째 가방에도 담을 수 있다.
	// -> values 큐는 반복문이 진행될 때마다 상태가 초기화될 필요 X
	priority_queue<int> values; 
	int i = 0;
	while (!bag.empty()) {
		int weigth = bag.top();
		bag.pop();

		for ( ; i < jewel.size(); i++) {
			if (jewel[i].first <= weigth) // 아직 비어있는 가방들 중 용량이 가장 작은 가방에 담을 수 있는 보석인지 판별
				values.push(jewel[i].second);
			else // jewel은 보석의 무게를 기준으로 오름차순 -> i번째 보석을 담을 수 없다면 그 뒤의 보석들도 어차피 담을 수 없으므로 break
				break;
		}

		if (!values.empty()) {
			max_val += values.top(); // 현재 가방에 담을 수 있는 보석들 중 가장 가치가 큰 보석을 담는다.
			values.pop();
		}
	}

	cout << max_val;

	return 0;
}
