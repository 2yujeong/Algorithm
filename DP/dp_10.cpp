/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

동전의 여러 단위가 입력으로 주어지며 각 단위의 동전들은 무한정 쓸 수 있다. 
이 동전들을 이용하여 거스름돈을 낸다고 할 때 필요한 동전의 최소개수를 출력하는 문제.

dp[j] = 거스름돈의 액수가 j일 때 거슬러주기 위해 필요한 동전의 최소개수
0-1 냅색 알고리즘의 DP 테이블 설계 방식은 dp_9.cpp(https://github.com/2yujeong/Algorithm/blob/master/DP/dp_9.cpp)에서 참고할 수 있다.

시간복잡도는 O(nm)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int coin;
		cin >> coin;

		coins.push_back(coin);
	}

	int m;
	cin >> m;

	vector<int> dp(m + 1, 501);
	dp[0] = 0; // 초기화해주지 않으면 dp[j - coins[i]] + 1이 무조건 502, dp[j]가 무조건 501이 나와 min값이 항상 501만 저장된다.

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			dp[j] = min(dp[j - coins[i]] + 1, dp[j]); // j의 범위가 coins[i]부터 시작이므로 dp를 업데이트하는 반복문은 dp[0] + 1과 dp[j]를 비교하는 과정부터 시작된다 -> dp[0]만 0으로 처음에 초기화해주면 맨처음(i = 0일 때) dp 업데이트 반복문이 돌 때 0 + 1 < 501이므로 dp[0] 제외 모든 값이 501이었던 dp 배열이 제대로된 min값으로 초기화 된다.
		}
	}

	cout << dp[m];

	return 0;
}
