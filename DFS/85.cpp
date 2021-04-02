/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

N개의 수로 이루어진 수열의 사이사이에 N - 1개의 연산자를 하나씩 끼워 넣을 때 만들어지는 수식들 중 연산 결과가 최대 / 최소인 결과 값을 출력하는 문제.
삼성 SW역량평가 기출문제이며 백준에서도 풀어볼 수 있다. (https://www.acmicpc.net/problem/14888)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, max_val = -2147000000, min_val = 2147000000;
int num[11];
int op[4];

void dfs(int level, int value) {
	if (level == n) {
		if (value > max_val)
			max_val = value;
		if (value < min_val)
			min_val = value;

		return;
	}

	if (op[0] > 0) {
		op[0]--;
		dfs(level + 1, value + num[level]);
		op[0]++;
	}
	if (op[1] > 0) {
		op[1]--;
		dfs(level + 1, value - num[level]);
		op[1]++;
	}
	if (op[2] > 0) {
		op[2]--;
		dfs(level + 1, value * num[level]);
		op[2]++;
	}
	if (op[3] > 0) {
		op[3]--;
		dfs(level + 1, value / num[level]);
		op[3]++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(1, num[0]);

	cout << max_val << "\n" << min_val;

	return 0;
}
