/*
문제 출처 : https://www.acmicpc.net/problem/11055 (백준 온라인 저지)

수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 문제.

이전에 풀었던 '최대 부분 증가 수열' 문제와 동일한 방식으로 DP 테이블을 설계해서 풀었다.
(https://github.com/2yujeong/Algorithm/commit/5f7b0102fb6e0f4092e1ad54b2ea022536709c57)

v 배열은 입력받은 수열 원소들을 차례대로 저장하며 
dp 배열은 arr[1]부터 arr[i]까지의 원소들로 구성된 수열에 대해 원소들의 합이 가장 큰 증가 부분 수열의 길이를 dp[i]에 저장한다. 
 '최대 부분 증가 수열' 문제와 다른 점은 dp에 부분 수열의원소의 수가 아닌 원소들의 합을 저장하기 때문에
dp[1]을 1이 아닌 입력받은 v[1]으로 초기화해줘야 한다.
dp[2]의 경우 v[2]가 v[1]보다 작은 경우 증가 부분 수열이 만들어지지 않으므로 자기 자신만 새로운 수열에 포함되어 dp[2] = v[2]가 되며
v[2]가 v[1]보다 큰 경우 dp[1]에 저장된 v[1] 기준의 증가 부분 수열의 맨 끝에 자신을 추가하면 되므로 dp[2] = dp[1] + v[2]가 된다.
이와 같이 수열에서 자신보다 앞에 있는 원소들 중 자신보다 작은 원소를 발견하면
그 작은 원소를 기준으로 합이 가장 큰 증가 부분 수열의 맨 끝에 자기 자신만 추가하면 길이가 1 늘어난 새로운 증가 부분 수열을 구할 수 있다.
따라서 자신보다 앞에 있는 원소들을 대상으로 위와 같은 비교 과정(자신보다 작은 원소인지 확인)을 거치고 그중에서도 원소들의 합이 최대인 증가 부분 수열을 만드는 원소(j)의 맨 끝에 자신을 추가한다는 의미로 dp[j] + v[i]를 해주면 dp 배열을 채울 수 있다.

구현하면서 주의할 점은 n이 1인 경우에는 dp 테이블을 채우는 for문이 실행되지 않으므로 
result 변수의 초기값은 입력 받은 v[i]로 설정해줘야 한다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; 
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1] = v[1];
	int result = v[1];

	for (int i = 2; i <= n; i++) {
		int biggest = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (v[j] < v[i]) {
				biggest = max(biggest, dp[j]);
			}
		}

		dp[i] = biggest + v[i];
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}
