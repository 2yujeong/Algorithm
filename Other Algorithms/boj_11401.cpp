/*
문제 출처 : https://www.acmicpc.net/problem/11401 (백준 온라인 저지)

자연수 N과 정수 K가 주어졌을 때 이항 계수 (N, K)를 10,007로 나눈 나머지를 구하는 문제.

이전에 풀었던 이항 계수 2에서는 조합 nCk를 구하는 점화식과 2차원 DP 배열을 이용하여 문제를 해결할 수 있었다.
(https://github.com/2yujeong/Algorithm/commit/d12c75e08481b6cd107d60e4566433b12f422d2c)
이항 계수 3은 N과 mod 연산을 해야 하는 p(1,000,000,007)가 매우 크기 때문에 2차원 배열을 선언하면 메모리 초과로 인해 문제를 풀 수 없다.
따라서 메모리를 O(n^2)만큼 쓰지 않는 다른 방법을 써야 하는데, 조합의 정의 중 factorial을 이용하여 계산하는 방법을 이용하면 메모리를 O(n)만큼만 써서 풀 수 있다.

factorial로 계산하는 조합의 정의는 다음과 같다.
 nCk = n! / (k!(n - k)!)
분자 n!을 A, 분모 k!(n - k)!을 B라고 정의하면 구하고자 하는 것은 다음과 같이 정의할 수 있다.
 (A / B) % p = (AB^(-1)) % p  (p = 1,000,000,007)
문제의 답에는 위와 같이 mod p 연산이 적용되어야 하는데, 
mod 연산은 분수 꼴에 대해서는 분배 법칙이 성립하지 않기 때문에 AB^(-1)에 대해 A와 B에 mod p를 분배할 수 없다.
이때 페르마의 소정리를 이용하면 AB^(-1)에 mod p를 분배하지 않고도 위에서 구하고자 했던 A, B, p에 관한 식을 풀 수 있다.

[참고] 페르마의 소정리 : p가 소수이고 a, p가 서로소이면, a^(p - 1)을 p로 나눈 나머지는 언제나 1이다.
이를 문제에 대입하면 B^(p - 1) % p = 1이 성립하므로 (AB^(-1)) % p = ((A % p)(B^(p - 2) % p)) % p가 성립한다.
따라서 factorial과 B에 대한 거듭제곱만 구현해주면 O(n) space에 문제를 해결할 수 있다.

시간복잡도는 factorial 함수가 O(n), 거듭 제곱 구현이 p = p / 2를 p가 1이 될 때까지 반복하므로 O(log p)이므로
총 시간복잡도는 O(n + log p)가 된다.
*/

#include <iostream>
using namespace std;

long long fac[4000001];

int main() {
	int n, k;
	cin >> n >> k;

	long long p = 1000000007;

	// factorial 구현
	fac[0] = 1;
	fac[1] = 1;

	for (int i = 2; i <= n; i++) { 
		fac[i] = (fac[i - 1] * i) % p;
	}

	// 거듭 제곱 구현 - 지수를 2로 나눈 후 전체를 제곱하는 과정 반복
	long long B = (fac[k] * fac[n - k]) % p; // 밑(result에 곱해져 갈 수)
	long long idx = p - 2; // 지수
	long long result = 1; // 최종값이 될 변수

	while (idx > 0) {
		if (idx % 2 == 1) {
			result *= B;
			result %= p;
		}

		B = (B * B) % p;
		idx /= 2;
	}

	cout << ((fac[n] % p) * (result % p)) % p;

	return 0;
}
