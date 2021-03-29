/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

벨만 포드 알고리즘을 이용하여 출발 정점에서 도착 정점으로 가는 최소비용을 구하는 문제.

참고 : 벨만 포드 알고리즘은 음의 사이클이 존재하지 않는다는 전제 조건이 존재(음의 사이클을 계속 돌수록 비용이 감소하므로 경로가 끝나지 않기 때문)
정점이 N개일 때 N개 이상의 간선을 통한 최소비용 경로가 존재하면 음의 사이클이 존재한다는 뜻이므로 벨만 포드 알고리즘을 이용할 수 없다. -> 벨만 포드 알고리즘은 최대 N - 1개의 간선을 이용하는 경로까지만 탐색한다. 

시간복잡도는 m개의 모든 간선 탐색을 n번 진행하므로 O(nm)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class edge {
public:
	int v1;
	int v2;
	int val;

	edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	vector<int> cost(n + 1, 2147000000); // 굳이 2차원 배열 쓸 필요 X

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(edge(a, b, c));
	}

	int src, dst;
	cin >> src >> dst;

	cost[src] = 0;

	for (int i = 1; i < n; i++) { // i개의 간선을 지나는 경로들의 비용 계산하고 최소비용이면 cost에 저장
		for (int j = 0; j < m; j++) { // edges에 저장된 모든 간선에 대해 진행
			if (cost[edges[j].v1] != 21470000 && cost[edges[j].v1] + edges[j].val < cost[edges[j].v2]) 
				cost[edges[j].v2] = cost[edges[j].v1] + edges[j].val;
		}
	}

	for (int i = 0; i < m; i++) { // 음의 사이클이 존재하는지 확인
		// 위의 for문에서 최대 n - 1개의 간선을 지나는 경로까지는 탐색이 된 상태, 만약 n개의 간선을 지나는 경로에서 비용이 감소한다면 음의 사이클 존재한다는 뜻
		if (cost[edges[i].v1] != 21470000 && cost[edges[i].v1] + edges[i].val < cost[edges[i].v2]) {
			cout << -1;

			exit(0);
		}
	}

	cout << cost[dst];

	return 0;
}
