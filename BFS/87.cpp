/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

지도 정보가 주어질 때 섬의 개수를 구하는 기본적인 BFS 문제.

시간복잡도는 map 전체 탐색을 위한 이중 for문 때문에 O(n^2)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[21][21];
queue<pair<int, int> > q;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++;
				map[i][j] = 0;
				q.push({ i, j });

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					// 상하좌우
					if (x - 1 >= 0 && map[x - 1][y] == 1) {
						q.push({ x - 1, y });
						map[x - 1][y] = 0;
					}
					if (x + 1 < n && map[x + 1][y] == 1) {
						q.push({ x + 1, y });
						map[x + 1][y] = 0;
					}
					if (y - 1 >= 0 && map[x][y - 1] == 1) {
						q.push({ x, y - 1 });
						map[x][y - 1] = 0;
					}
					if (y + 1 < n && map[x][y + 1] == 1) {
						q.push({ x, y + 1 });
						map[x][y + 1] = 0;
					}

					// 대각선
					if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == 1) {
						q.push({ x - 1, y - 1 });
						map[x - 1][y - 1] = 0;
					}
					if (x - 1 >= 0 && y + 1 < n && map[x - 1][y + 1] == 1) {
						q.push({ x - 1, y + 1 });
						map[x - 1][y + 1] = 0;
					}
					if (x + 1 < n && y - 1 >= 0 && map[x + 1][y - 1] == 1) {
						q.push({ x + 1, y - 1 });
						map[x + 1][y - 1] = 0;
					}
					if (x + 1 < n && y + 1 < n && map[x + 1][y + 1] == 1) {
						q.push({ x + 1, y + 1 });
						map[x + 1][y + 1] = 0;
					}
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
