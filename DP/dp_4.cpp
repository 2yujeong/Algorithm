/*
N 길이의 수열이 주어질 때, 그 안에서의 최대 부분 증가수열(가장 길게 증가하는 원소들의 집합)의 길이를 출력하는 Longest Increasing Subsequence 문제.

arr 배열은 입력받은 수열 원소들을 차례대로 저장하며 dp 배열은 arr[1]부터 arr[idx]에 저장된 원소로 끝나는 부분집합에 대한 최대 부분 증가수열의 길이를 dp[idx]에 저장한다. 
dp[1]은 부분집합의 원소가 하나이므로 무조건 1이다. 
dp[2]는 arr[2]가 arr[1]보다 작은 경우 부분 증가수열이 만들어지지 않으므로 자기 자신만 새로운 수열에 포함된 길이인 1이 되며, arr[2]가 arr[1]보다 큰 경우 dp[1]에 저장된 arr[1]기준의 부분 증가수열의 맨 끝에 자신을 추가하면 되므로 dp[2] = dp[1] + 1 = 2가 된다.
이와 같이 수열에서 자신보다 앞에 있는 원소들 중 자신보다 작은 원소들이 있다면 그 작은 원소 기준의 최대 부분 증가수열의 맨 끝에 자기 자신만 추가하면 길이가 1 늘어난 새로운 부분 증가수열을 구할 수 있다.
따라서 자신보다 앞에 있는 원소들을 대상으로 위와 같은 비교 과정(자신보다 작은 원소인지 확인)을 거치고 그중에서도 길이가 최대인 부분 증가수열을 만드는 원소(i)의 맨 끝에 자신을 추가한다는 의미로 dp[i] + 1을 해주면 dp 배열을 채울 수 있다.

시간복잡도는 O(n^2)
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
