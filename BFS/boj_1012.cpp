/*
문제 출처 : https://www.acmicpc.net/problem/1012 (백준 온라인 저지)

어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있다.
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.)
배추밭의 정보가 주어질 때 모든 배추에 지렁이가 한 번 이상 도달하기 위해선 최소 몇 마리의 지렁이가 필요한지 구하는 문제.

기본적인 BFS 문제이다.

시간복잡도는 O(nm)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
    
	while (t--) {
		int m, n, k, cnt = 0;
		cin >> m >> n >> k;
        
        vector<vector<int>> map(n, vector<int>(m, 0));

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
            
			map[b][a] = 1;
		}

		queue<pair<int, int> > q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					cnt++;
					q.push(make_pair(i, j));
					map[i][j] = 0;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						if (x - 1 >= 0 && map[x - 1][y] == 1) {
							map[x - 1][y] = 0;
							q.push(make_pair(x - 1, y));
						}
						if (x + 1 < n && map[x + 1][y] == 1) {
							map[x + 1][y] = 0;
							q.push(make_pair(x + 1, y));
						}
						if (y - 1 >= 0 && map[x][y - 1] == 1) {
							map[x][y - 1] = 0;
							q.push(make_pair(x, y - 1));
						}
						if (y + 1 < m && map[x][y + 1] == 1) {
							map[x][y + 1] = 0;
							q.push(make_pair(x, y + 1));
						}
					}
				}
			}
		}

		cout << cnt << endl;
	}
}
