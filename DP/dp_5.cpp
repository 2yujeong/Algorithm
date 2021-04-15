/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

위->아래 방향으로 1 ~ N이 오름차순으로 나열된 그림과 순서 없이 같은 방향(위->아래)으로 나열된 그림이 있다.
두 그림 간 서로 같은 수끼리 선으로 연결한다고 할 때 선이 겹치지 않게 최대 몇 개의 선을 연결할 수 있는지 구하는 문제.
입력으로는 순서 없이 나열된 그림의 N개의 수의 정보가 주어진다.

풀이는 dp_4번 문제와 완전히 같으며 문제가 여러 형태로 응용되어 출제되었을 때 문제를 읽고 LIS 문제인 걸 파악하는 게 중요하다. 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[1] = 1;
	int result = -1;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
		int max = 0; // 수열에서 arr[i]의 앞에 arr[i]보다 작은 수가 없는 경우 for문이 돌지 않으면 max값이 새로 초기화되지 않으므로 max의 초기값은 0(자신의 앞에 자신보다 작은 수가 없는 경우의 증가수열의 길이)이어야 한다.
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;

		if (dp[i] > result)
			result = dp[i];
	};

	cout << result;

	return 0;
}
