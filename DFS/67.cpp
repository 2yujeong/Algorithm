/*
가중치 방향그래프에서 1번 정점에서 N번 정점으로 가는 최소비용을 구하는 문제.
인접 행렬을 이용하여 DFS를 구현하였다.
*/

#include <iostream>
#include <algorithm>
#include <string.h> // memset 함수

using namespace std;

int map[21][21];
int check[21];
int n, cost = 2147000000;

void DFS(int v, int sum) {
	if (v == n) {
		if (sum < cost)
			cost = sum;
		
		return;
	}
	
	for (int i = 2; i <= n; i++) {
		if (map[v][i] != -1 && check[i] == 0) {
			check[i] = 1;
			DFS(i, sum + map[v][i]);
			check[i] = 0;
		}
	}
}

int main() {
	int m;
	cin >> n >> m;

	for (int i = 0; i < 21; i++) {
		memset(map[i], -1, sizeof(int) * 21); // -1로 map 초기화
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		map[a][b] = c;
	}

	check[1] = 1;
	DFS(1, 0);

	cout << cost;

	return 0;
}
