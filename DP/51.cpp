/*
똑같은 코드에 ios::sync_with_stdio(false)를 선언했음에도 cin, cout은 Timelimit이 떴다. 
cin, cout이 더 사용하기 편하고 ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)로 속도가 느리다는 단점을 해결할 수 있지만 그럼에도 scanf, printf 속도로만 정답이 나오는 경우가 있다. 
이제까지 ios::sync_with_stdio(false) 문제를 풀면서 입출력 때문에 Timelimit이 뜬 경우는 없었으므로 흔한 경우는 아닌 거 같지만 시간을 조금이라도 더 줄이기 위해서는 scanf, printf 사용을 권장한다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[701][701], dp[701][701];

int main() {
	int h, w;
	scanf_s("%d %d", &h, &w);

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf_s("%d", &map[i][j]);

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}

	int n, m, max = -1;
	scanf_s("%d %d", &n, &m);

	for (int i = n; i <= h; i++) {
		for (int j = m; j <= w; j++) {
			int tmp = dp[i][j] - dp[i - n][j] - dp[i][j - m] + dp[i - n][j - m];
			
			if (tmp > max)
				max = tmp;
		}
	}

	printf("%d", max);

	return 0;
}
