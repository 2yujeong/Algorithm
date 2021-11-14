/*
문제 출처 : https://www.acmicpc.net/problem/11051 (백준 온라인 저지)

자연수 N과 정수 K가 주어졌을 때 이항 계수 (N, K)를 10,007로 나눈 나머지를 구하는 문제.

이항 계수란 이항식을 이항 정리로 전개했을 때의 각 항의 계수를 말한다. 
이는 조합을 이용하여 구할 수 있기 때문에, 이항 계수는 주어진 크기(N)의 집합에서 원하는 개수(K)만큼 순서없이 뽑는 조합의 가짓수를 일컫는 말이기도 하다.
즉 입력 N, K에 대한 조합 nCk를 구하여 10,007로 나누면 되는 문제다.
nCk를 구현할 때는 다음과 같은 점화식을 이용한다.
 - nCk = 1 (if n = k or k = 0)
 - nCk = (n - 1)Ck + (n - 1)C(k - 1) (otherwise)
이때 단순 재귀 함수 호출이나 반복문을 이용하면 중복이 너무 많이 발생하므로 시간복잡도를 통과할 수 없다.
따라서 메모이제이션을 이용한 DP로 풀어야 한다.
먼저 조합의 결과를 저장할 2차원 배열 dp를 선언하고 재귀 함수를 이용하여 dp 배열을 채워간다.
만약 dp[i][j]에 값이 이미 채워져 있다면 재귀를 더 호출하지 않고 바로 배열의 값 dp[i][j]를 반환하는 방식으로 중복을 줄일 수 있다.

시간복잡도는 O(n^2)
*/

#include <iostream>
using namespace std;

int dp[1001][1001];

int comb(int n, int k) {
	if (n == k || k == 0)
		return dp[n][k] = 1;

	if (dp[n][k] > 0)
		return dp[n][k];

	return dp[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << comb(n, k);

	return 0;
}
