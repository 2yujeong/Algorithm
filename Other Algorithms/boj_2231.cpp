/*
문제 출처 : https://www.acmicpc.net/problem/2231 (백준 온라인 저지)

어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 
어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구하는 문제.

1부터 시작하여 모든 수들의 분해합을 구해보는 브루트 포스 문제이다.
n의 분해합에는 자기자신이 포함되어야 하므로 N 이상의 수들의 분해합은 무조건 N보다 크다.
따라서 N - 1까지의 수들에 대해서만 구해보면 된다.
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = i, num = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}

		if (sum == n) {
			cout << i;
			
			return 0;
		}
	}

	cout << 0;

	return 0;
}
