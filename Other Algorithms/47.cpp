/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

높이가 자신의 상하좌우 지역의 높이보다 높은 지역을 봉우리 지역이라고 할 때 봉우리 지역의 개수를 출력하는 문제.
2차원 배열과 2중 for문을 사용하여 각 지역마다 자신의 상하좌우 지역의 높이와 비교하였다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int h;
			cin >> h;

			map[i][j] = h;
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && map[i - 1][j] >= map[i][j]) // 위
				continue;
			if (i < 50 && map[i + 1][j] >= map[i][j]) // 아래
				continue;
			if (j > 0 && map[i][j - 1] >= map[i][j]) // 왼쪽
				continue;
			if (j < 50 && map[i][j + 1] >= map[i][j]) // 오른쪽
				continue;

			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
