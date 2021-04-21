/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

N x N 계곡의 돌다리 격자정보가 주어진다. 돌다리 격자정보는 각 돌다리를 건널 때 소비되는 에너지의 양을 의미한다. 
(1, 1)에서 (N, N)까지 가는 데 드는 에너지의 최소량을 구하는 문제.
이때 이동은 최단거리 이동을 한다. 즉, 현재 지점에서 오른쪽 또는 아래에 있는 돌다리로만 이동할 수 있다.

dp_7번 문제를 Top-Down 방식으로 풀었다. DP 테이블 설계는 dp_7.cpp 파일에서 확인할 수 있다.
재귀함수 topDown()을 이용하였으며 topDown(i, j)는 i, j돌다리까지 오는 데에 드는 에너지의 최소량을 의미한다.
Top-Down 방식으로 문제를 해결할 때에는 재귀함수 호출이 겹치는 경우가 있으므로 DP 테이블을 이용한 메모이제이션까지 구현해줘야 타임리밋이 뜨지 않는다.

시간복잡도는 dp 테이블을 활용하는 경우 제외 n x n개의 좌표에 대해 재귀함수를 호출하므로 O(n^2)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int info[21][21];
int dp[21][21];

int topDown(int i, int j) {
	if (dp[i][j] > 0) // 메모이제이션 이용. 안 해주면 Timelimit
		return dp[i][j];

	if (i == 0 && j == 0) 
		return dp[0][0] = info[0][0];
	
	if (i == 0)
		return dp[i][j] = topDown(i, j - 1) + info[i][j];

	if (j == 0)
		return dp[i][j] = topDown(i - 1, j) + info[i][j];

	return dp[i][j] = min(topDown(i - 1, j), topDown(i, j - 1)) + info[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;

			info[i][j] = a;
		}
	}

	topDown(n - 1, n - 1);

	cout << dp[n - 1][n - 1];

	return 0;
}
