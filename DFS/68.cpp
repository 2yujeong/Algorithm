/*
67번 문제와 같이 최소비용을 찾는 문제이며 인접 행렬 대신 인접 리스트로 DFS를 구현한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > map;
int check[21];
int n, cost = 2147000000;

void DFS(int v, int sum) {
	if (v == n) {
		if (sum < cost)
			cost = sum;
		
		return;
	}
	
	for (int i = 0; i < map[v].size(); i++) {
		if (check[map[v][i].first] == 0) {
			check[map[v][i].first] = 1;
			DFS(map[v][i].first, sum + map[v][i].second);
			check[map[v][i].first] = 0;
		}
	}
}

int main() {
	int m;
	cin >> n >> m;

	map.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		map[a].push_back(make_pair(b, c));
	}

	check[1] = 1;
	DFS(1, 0);

	cout << cost;

	return 0;
}
