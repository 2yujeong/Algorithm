/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

메모이제이션을 이용한 이항계수 문제.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int memory[21][21];

int comb(int n, int r) {
	if (memory[n][r] > 0)
		return memory[n][r];

	if (r == 0 || n == r)
		return 1;

	return comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
	int n, r;
	cin >> n >> r;

	cout << comb(n, r) << endl;

	return 0;
}
