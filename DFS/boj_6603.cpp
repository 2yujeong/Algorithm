/*
문제 출처 : https://www.acmicpc.net/problem/6603 (백준 온라인 저지)

K개의 수가 주어졌을 때, 그 중 6개의 로또 번호를 고르는 모든 경우를 출력하는 문제.
기본적인 조합탐색 문제로 재귀를 이용하여 DFS로 풀 수 있다.

시간복잡도는 서로 다른 k개의 수 중 겹치지 않도록 r개를 선택하는 방법의 수이므로 O(kCr)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result(6);
vector<int> v;

void dfs(int level, int value) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << " ";
		}

		cout << endl;
		return;
	}

	for (int i = value; i < v.size(); i++) {
		result[level] = v[i];
		dfs(level + 1, i + 1);
	}
}

int main() {
	int k;
	cin >> k;

	while (k != 0) {
		v.clear();

		for (int i = 0; i < k; i++) {
			int n;
			cin >> n;

			v.push_back(n);
		}

		dfs(0, 0);
		cout << endl;

		cin >> k;
	}

	return 0;
}
