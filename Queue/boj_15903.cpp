/*
문제 출처 : https://www.acmicpc.net/problem/15903 (백준 온라인 저지)

카드 합체 놀이는 다음과 같이 진행된다.
 1. x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
 2. 계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.
이 카드 합체를 총 m번 하면 놀이가 끝난다. 
놀이가 끝난 뒤 n장의 카드에 쓰여있는 수를 모두 더한 값이 이 놀이의 점수가 된다.
n개의 카드의 정보와 합체 횟수 m이 주어질 때, 놀이가 끝나고 만들 수 있는 가장 작은 점수를 구하는 문제. 

우선순위 큐를 이용하여 놀이 진행 방법 그대로 구현해주면 되는 문제이다.
가장 작은 점수를 만들기 위해선 합체 할 때마다 가장 작은 값의 카드 두 장을 골라서 합체해주면 된다.
입력 범위에 따라 큰 값들이 입력되면 int 범위를 벗어날 수 있으므로 long long 자료형으로 선언해야 통과할 수 있다.
유의할 점은 1번 조건에서의 x ≠ y는 두 카드가 서로 다른 카드라는 뜻으로 두 카드에 쓰여진 값이 같은 건 상관 없다.

시간복잡도는 O(nlog n + mlog n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	priority_queue<long, vector<long>, greater<long>> pq;
	long result = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		long a = pq.top();
		pq.pop();
		long b = pq.top();
		pq.pop();

		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result;

	return 0;
}
