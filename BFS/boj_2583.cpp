/*
문제 출처 : https://www.acmicpc.net/problem/2583 (백준 온라인 저지)

눈금의 간격이 1인 M X N 크기의 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그리면
이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
분리된 영역의 개수와 각 영역의 넓이를 오름차순으로 정렬하여 출력하는 문제.

큐를 이용한 BFS 방식으로 풀었다.
이때 입력받은 x, y 좌표를 이용하여 모눈종이에 직사각형을 그리는 과정을 구현하는 부분이 헷갈릴 수 있으므로
이 부분만 유의하면 어렵지 않게 풀 수 있다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> map(m, vector<int>(n));

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = m - y2; i < m - y1; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}

	vector<int> result;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				int size = 1;
				map[i][j] = 1;

				queue<pair<int, int>> q;
				q.push({ i, j });

				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[ny][nx] == 0) {
							size++;
							map[ny][nx] = 1;
							q.push({ ny, nx });
						}
					}
				}

				result.push_back(size);
			}
		}
	}

	sort(result.begin(), result.end());
	
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}
