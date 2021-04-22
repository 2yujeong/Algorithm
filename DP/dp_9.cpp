/*
가방에 담을 수 있는 무게의 한계값이 m일 때 가능한 보석의 최대가치를 구하는 문제.

시간복잡도는 O(nm)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, limit;
	cin >> n >> limit;

	vector<int> dp(limit + 1, 0);

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;

		for (int j = w; j <= limit; j++) {
			dp[j] = max(dp[j - w] + v, dp[j]);
		}
	}

	cout << dp[limit];

	return 0;
}
