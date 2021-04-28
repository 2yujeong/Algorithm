/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

가방에 담을 수 있는 무게의 한계값이 m일 때 가능한 보석의 최대가치를 구하는 문제.

[DP 테이블 설계]
- dp[j] = 가방에 담을 수 있는 무게의 한계값이 j일 때 가능한 보석의 최대가치
- 입력의 경우 보석의 무게와 가치(w, v)가 총 n번 들어온다. n개의 보석 정보가 입력될 때마다 dp 테이블을 업데이트 한다.
- i번째 보석의 정보(w, v)가 입력되면 각각의 dp[j]에 대해 w만큼의 무게를 가방에서 덜고 현재의 보석을 넣으면 기존보다 가치가 더 커질지 아니면 오히려 작아질지를 판별한다.
-> dp[j - w] + v(현재 보석의 무게만큼을 가방을 비웠을 때의 최대 가치 + 비워진 자리에 현재의 보석이 들어가므로 현재의 보석의 가치)와 dp[j](0번째부터 i - 1번째 보석들로만 가방을 채웠을 때의 최대 가치)를 비교하여 더 큰 값을 dp[j]에 저장한다.
- 보석을 한꺼번에 2개 이상 넣는 경우는 생각할 필요가 없다. (dp[j - 2w]가 최대가치인 경우라면 이미 dp[j - w]에 해당 보석이 하나 포함된 상태이므로 dp[j - w] + v만 고려하면 된다.)

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
