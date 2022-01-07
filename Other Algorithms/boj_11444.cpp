/*
문제 출처 : https://www.acmicpc.net/problem/11444 (백준 온라인 저지)

피보나치 수는 0과 1로 시작하며, Fn = Fn-1 + Fn-2 (n ≥ 2)를 만족하는 수이다.
n이 주어졌을 때, n번째 피보나치 수를 구하는 문제.

n의 범위가 매우 크기 때문에 메모이제이션을 적용하면 메모리가 초과되며, 일반적인 점화식 또는 재귀 함수를 사용하면 시간초과가 뜬다.
행렬을 이용한 피보나치 수의 점화식을 이용하여, 행렬의 거듭제곱을 구현해 풀어야 한다.

[행렬을 이용한 피보나치 수 점화식]
F1인 1이 1행, F0인 0이 2행에 배치된 2 X 1 행렬 [[1], [0]]을 생각해보자.
이 행렬에 [[1, 1], [1, 0]]을 곱해주면 두 수 F1, F0을 더한 F2 = 1이 1행에, F1 = 1이 2행에 위치하게 된다.
이렇게 얻은 [[1], [1]]에 [[1, 1], [1, 0]]를 다시 한 번 곱해주면 F2와 F1를 더한 F3 = 2가 1행에, F2 = 1이 2행에 위치한다.
즉, [[1, 1], [1, 0]]를 n번 곱했을 때 얻은 행렬의 1행의 값이 n번째 피보나치 수가 된다.
 => [[Fn+2], [n+1]] = [[1, 1], [1, 0]] * [[Fn+1], [Fn]]
이 점화식을 정리하면 다음과 같이 나타낼 수 있다.
 => [[Fn+1, Fn], [Fn, Fn-1]] = [[1, 1], [1, 0]]^n
코드에서 행렬끼리 곱하는 과정을 3중 for문을 이용하여 구현한 함수가 multiple 함수이다.

[거듭 제곱 구현]
거듭 제곱은 지수를 2로 나눈 후 전체를 제곱하는 과정 반복함으로써 코드로 구현할 수 있다.
ex) a^24 = (a^12)^2 // 지수를 2로 나눈 결과가 짝수인 경우에는 지수를 2로 나누고 전체를 제곱한다.
	= ((a^6)^2)^2
	= (((a^3)^2)^2)^2 
	= (((a * a^2)^2)^2)^2 // 지수를 2로 나눈 결과가 홀수인 경우에는 a가 하나 빠져나와서 지수 계산에 더하기가 생긴다.
	= a^(2*2*2 + 2*2*2*2)

시간복잡도는 거듭 제곱을 구현하는 과정에서 multiple 함수와 n /= 2를 n이 1이 될 때까지 반복하므로 O(log n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> multiple(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2) {
	vector<vector<long long>> result(2, vector<long long>(2));

	// 행렬 곱 수행
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] %= 1000000007;
		}
	}

	return result;
}

int main() {
	long long n;
	cin >> n;

	vector<vector<long long>> result = { {1,0},{0,1} }; // 초기 정답 배열은 단위 행렬로 초기화
	vector<vector<long long>> base = { {1,1},{1,0} }; // 밑(result에 곱해져 갈 행렬)

	while (n > 0) { // 거듭 제곱 구현 - 지수 n을 2로 나눈 후 전체를 제곱하는 과정 반복
		if (n % 2 == 1)
			result = multiple(result, base);
		base = multiple(base, base);
		n /= 2;
	}

	cout << result[0][1];

	return 0;
}
