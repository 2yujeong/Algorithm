/*
문제 출처 : https://www.acmicpc.net/problem/1940 (백준 온라인 저지)

주몽의 명에 따라 야철대장이 갑옷을 만들려고 한다.
갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있는데, 두 가지의 재료의 번호의 합이 M이 되면 하나의 갑옷을 만들 수 있다.
야철대장이 가지고 있는 재료를 가지고 총 몇 개의 갑옷을 만들 수 있는지 구하는 문제.

재료들을 번호에 따라 오름차순으로 정렬하고, 두 개의 포인터를 이용하여 각 포인터가 가리키는 값들의 합이 M과 같은지, 작은지, 큰지에 따라 포인터를 증감시킴으로써 풀 수 있다.
먼저 초기화 시 포인터1은 제일 작은 번호를, 포인터2는 제일 큰 번호를 가리키게 하고
두 포인터가 가리키는 재료 번호의 합이 M과 같다면 포인터1은 증가를, 포인터2는 감소를 한다.
만약 합이 M보다 작다면 더 큰 값이 필요하다는 뜻이므로, 남은 재료들 중 가장 작은 번호를 가리키고 있던 포인터1을 증가시키고
M보다 크다면 더 작은 값이 필요하다는 뜻이므로 남은 재료들 중 가장 큰 번호를 가리키고 있던 포인터2를 감소시킨다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int pos1 = 0, pos2 = n - 1, answer = 0;
	while (pos1 < pos2) {
		if (v[pos1] + v[pos2] == m) {
			answer++;
			pos1++;
			pos2--;
		}

		if (v[pos1] + v[pos2] < m)
			pos1++;

		if (v[pos1] + v[pos2] > m)
			pos2--;
	}

	cout << answer;

	return 0;
}
