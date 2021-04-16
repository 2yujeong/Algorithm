/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

N개의 벽돌들에 대한 밑면의 넓이, 높이, 무게 정보가 주어진다. 이 벽돌들로 탑을 쌓는데 밑에 쌓인 벽돌은 위에 쌓인 벽돌보다 무게가 더 무겁고 넓이가 더 커야한다. 
이러한 조건을 만족하면서 가장 높은 탑을 쌓았을 때의 탑의 높이를 출력하는 문제.

밑에 쌓이려면 밑면의 넓이가 더 큼과 동시에 무게가 더 무거워야 하는 게 주어진 조건인데 먼저 입력 받은 벽돌이 나중에 입력받은 벽돌보다 무조건 밑에 쌓여야 한다고 착각해서 초반에 헤맸다.
입력 순서를 거스르지 않으며 넓이 & 무게를 같이 비교하는 게 아니라 
넓이 or 무게를 기준으로 내림차순으로 먼저 정렬해놓고, 이렇게 정렬된 순서를 거스르지 않도록 LIS 방식으로 무게 or 넓이를 비교해가며 풀어야 한다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class block {
public:
	int area, height, weight;
};

bool comp(const block a, const block b) {
	return a.weight > b.weight; // 무게를 기준으로 내림차순 정렬
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int answer = -1;
	vector<block> blocks(n); // 입력받은 벽돌들의 정보 저장
	vector<int> dp(n); // dp[i]는 sort로 정렬된 blocks 기준 blocks[i]가 탑의 맨 위에 쌓일 때의 최대 높이 저장

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		blocks[i] = { a, b, c };
	}

	sort(blocks.begin(), blocks.end(), comp);
	dp[0] = blocks[0].height;

	for (int i = 0; i < n; i++) {
		int max = 0; // 자신보다 무게가 더 무겁고 넓이가 더 큰 블럭이 없는 경우 for문이 돌지 않으면 max값이 새로 초기화되지 않으므로 max의 초기값은 0(자신의 밑에 쌓인 블럭의 개수)이어야 한다.
		for (int j = i - 1; j >= 0; j--) { // 자신보다 무거운 블럭들 중 넓이도 자신보다 더 큰 블럭들 찾기
			if (blocks[j].area > blocks[i].area && dp[j] > max) // 넓이도 더 크고 자신이 맨 위에 쌓일 수 있는 탑들 중에서 높이가 가장 큰 경우를 찾는다.
				max = dp[j];
		}
		dp[i] = max + blocks[i].height; // 가능한 탑들 중 가장 높은 탑에 자신까지 쌓인 탑의 높이를 자신의 dp 배열에 저장한다.

		if (dp[i] > answer) // n개의 블럭에 대한 모든 경우들 중 가장 높은 탑이 쌓이는 경우의 높이 찾기.
			answer = dp[i];
	}

	cout << answer;

	return 0;
}
