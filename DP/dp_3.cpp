/*
네트워크 선 자르기 문제와 동일한 DP 문제.
돌다리를 다 건너야 하는데 입력 N으로 돌의 개수가 주어지므로 DP[N + 1]까지 구하고 출력해야 한다.
중간에 발을 디딜 수 없는 작은 돌이 있는 경우가 추가되는 등의 응용 문제도 출제될 수 있으니 이러한 응용에 대해서도 생각해보는 게 좋겠다.

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

	for (int i = 3; i <= n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n + 1];

	return 0;
}
