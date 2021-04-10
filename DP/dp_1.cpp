/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

Nm의 네트워크 선을 1m 또는 2m 길이의 선으로 자르려고 할 때 자르는 방법의 개수를 출력하는 문제.

nm의 선이 주어졌을 때 자르는 방법의 개수를 f(n)이라고 하면 f(1) = 1, f(2) = 2은 직관적으로 알 수 있다.
f(3)의 경우 잘라진 맨 마지막 선이 1m인 경우와 2m인 경우로 나누어 생각할 수 있다. 
먼저 마지막 선이 1m인 경우, 앞의 2m의 선을 가능한 모든 방법대로 자르고 각각의 방법대로 자른 선들 뒤에 마지막 1m를 더해주면 총 3m의 선을 자른 게 된다. 따라서 그 방법의 수는 f(2)와 같다.
마지막 선이 2m인 경우, 앞의 1m의 선을 가능한 모든 방법대로 자르고 뒤에 마지막 2m를 더해주면 3m가 되므로 마찬가지로 그 방법의 수가 f(1)과 같다.
따라서 f(3) = f(2) + f(1) = 3을 구할 수 있으며 이를 토대로 점화식을 다음과 같이 세울 수 있다.
=> 점화식 : f(n) = f(n - 1) + f(n - 2)

시간복잡도는 O(n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[46];

int main() {
	ios::sync_with_stdio(false); // 동기화 해제 - C++ 독립 버퍼 사용
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}
