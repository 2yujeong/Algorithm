/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

dp_1번과 같은 문제를 재귀함수 + 메모이제이션을 이용하여 해결한다.
동적계획법은 정확히는 Bottom-Up 방식을 의미한다. Top-Down의 경우 단순 재귀 방식은 DP가 아니지만 메모이제이션을 함께 이용하면 재귀 실행 구조가 점화식과 비슷하기 때문에 넓은 의미에서 DP라고 보기도 한다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[46];

int topDown(int n) {
	if (dp[n] == 0)
		return dp[n] = topDown(n - 1) + topDown(n - 2);

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false); // 동기화 해제 - C++ 독립 버퍼 사용
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	cout << topDown(n);

	return 0;
}
