/*
문제 출처 : https://www.acmicpc.net/problem/4963 (백준 온라인 저지)

정사각형으로 이루어져있는 섬과 바다의 지도가 주어진다.
0은 바다, 1은 섬을 의미하며 
섬을 의미하는 한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 정사각형들은 서로 걸어서 이동할 수 있는 하나의 섬으로 본다.
지도에 존재하는 섬의 개수를 출력하는 문제.

큐를 이용하여 BFS 방식으로 풀 수 있다.
유의할 점은 대각선으로 연결된 구역까지도 하나의 섬으로 보기 때문에 
하나의 정사각형당 총 8개의 경우에 대해 탐색해야 한다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	int w, h;
	cin >> w >> h;
	
	while (w != 0 && h != 0) {
		vector<vector<int>> map(h, vector<int>(w));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					cnt++;
					map[i][j] = 0;
					queue<pair<int, int>> q;
					q.push({ i, j });

					while (!q.empty()) {
						int x = q.front().second;
						int y = q.front().first;
						q.pop();

						for (int k = 0; k < 8; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx >= 0 && ny >= 0 && nx < w && ny < h && map[ny][nx] == 1) {
								map[ny][nx] = 0;
								q.push({ ny, nx });
							}
						}
					}
				}
			}
		}

		cout << cnt << endl;
		cin >> w >> h;
	}

	return 0;
}
