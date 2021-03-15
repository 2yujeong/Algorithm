/*
DFS를 이용하여 1번 정점에서 N번 정점으로 갈 수 있는 경로의 수를 출력하는 문제.
재귀함수를 이용하였으며 가능한 모든 경로의 수를 출력해야 하기 때문에 완전탐색으로 구현하였다.
DFS는 인접 행렬을 이용한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int map[21][21];
int check[21];
int n, cnt = 0;

void DFS(int v) { // 재귀함수가 스택 구조를 이용하므로 재귀함수 대신 스택으로 구현해도 된다.
	if (v == n) {
		cnt++;
		return;
	}

	for (int i = 2; i <= n; i++) {
		if (map[v][i] == 1 && check[i] == 0) {
			check[i] = 1;
			DFS(i);
			check[i] = 0; // 모든 정점을 한 번씩 방문하는 게 아닌 모든 경로에 대해 탐색하는 게 목표이므로 하나의 경로가 끝나면 backtracking 후 새로 for문이 돌면서 경로를 계속 탐색할 수 있도록 0으로 초기화
		}
	}
}

int main() {
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
	}

	check[1] = 1;
	DFS(1);

	cout << cnt;

	return 0;
}
