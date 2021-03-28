/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

다익스트라 알고리즘을 이용하여 1번 정점에서 다른 모든 정점으로 가는 최소비용을 구하는 문제.

시간복잡도는 우선순위 큐를 사용하고 큐에 한 번에 들어갈 수 있는 간선 정보의 수가 최대 m이므로 push 연산 시 최악의 경우 O(logm)이 걸린다. 이 과정을 m개의 모든 간선에 대해 반복하므로 총 시간복잡도는 O(mlogm) = O(mlogn)이 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct comp { // priority_queue의 비교연산자는 함수가 아닌 구조체 형태로 연산자 오버로딩을 해줘야 한다.
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> dist(n + 1, 2147000000); // 1번 정점에서 n번 정점으로 가는 데 드는 최소비용 저장
	vector<vector<pair<int, int> > > list(n + 1); // 인접 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	dist[1] = 0; // 자기자신으로 가는 비용은 0
	pq.push({ 1, 0 });

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		list[a].push_back({ b, c });
	}

	while (!pq.empty()) {
		int v = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[v] < cost) // 코드의 효율성을 위해서 추가(부등호 사용하면 X). 없어도 정상 동작
			continue;

		for (int i = 0; i < list[v].size(); i++) {
			if (dist[list[v][i].first] > cost + list[v][i].second) {
				dist[list[v][i].first] = cost + list[v][i].second; // 최소비용 업데이트
				pq.push({ list[v][i].first, cost + list[v][i].second }); // 인접한 간선들 중 가중치가 가장 작은 간선을 O(1)에 찾기 위해 우선순위 큐에 저장
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] != 2147000000)
			cout << i << " : " << dist[i] << endl;
		else
			cout << i << " : impossible" << endl;
	}

	return 0;
}
