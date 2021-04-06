/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

토마토들이 모두 익는 최소 일수를 구하는 BFS 활용 문제.
백준에서도 풀어볼 수 있다. (https://www.acmicpc.net/problem/7576)

시간복잡도는 O(nm)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001];

class tomato {
public:
	int x, y, day;
};

queue<tomato> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, space = 0, cnt = 0;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) { // 익은 토마토인 경우
				q.push({ i, j, 0 });
				cnt++; // 익은 토마토의 개수 증가
			}
			else if (map[i][j] == -1) // 토마토가 들어있지 않을 경우
				space++; // 탐색이 필요 없는 칸의 개수 증가
		}
	}

	int x, y, day;
	while (!q.empty()) { // BFS 진행
		x = q.front().x;
		y = q.front().y;
		day = q.front().day;
		q.pop();

		if (x - 1 >= 0 && map[x - 1][y] == 0) {
			q.push({ x - 1, y, day + 1 });
			map[x - 1][y] = 1;
			cnt++;
		}
		if (x + 1 < n && map[x + 1][y] == 0) {
			q.push({ x + 1, y, day + 1 });
			map[x + 1][y] = 1;
			cnt++;
		}
		if (y - 1 >= 0 && map[x][y - 1] == 0) {
			q.push({ x, y - 1, day + 1 });
			map[x][y - 1] = 1;
			cnt++;
		}
		if (y + 1 < m && map[x][y + 1] == 0) {
			q.push({ x, y + 1, day + 1 });
			map[x][y + 1] = 1;
			cnt++;
		}
	}

	if (cnt == n * m - space)
		cout << day;
	else
		cout << -1;

	return 0;
}
