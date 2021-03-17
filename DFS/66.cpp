/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

64번 경로 탐색 문제와 같이 DFS를 이용하여 1번 정점에서 N번 정점으로 갈 수 있는 경로의 수를 출력하는 문제.
64번에서는 인접 행렬을 이용하여 DFS를 구현했고 이번에는 인접 리스트를 이용하였다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > map;
int check[21];
int n, cnt = 0;

void DFS(int v) {
	if (v == n) {
		cnt++;
		return;
	}
	
	for (int i = 0; i < map[v].size(); i++) {
		if (check[map[v][i]] == 0) {
			check[map[v][i]] = 1;
			DFS(map[v][i]);
			check[map[v][i]] = 0;
		}
	}
}

int main() {
	int m;
	cin >> n >> m;

	map.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		map[a].push_back(b);
	}

	check[1] = 1;
	DFS(1);

	cout << cnt;

	return 0;
}
