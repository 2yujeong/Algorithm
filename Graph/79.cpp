/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

우선순위 큐를 활용하여 프림 알고리즘으로 MST를 찾는 문제.
우선순위 큐에서 top을 꺼내 처리할 때 해당 pair를 pop 해주는 연산을 반복문 마지막에 구현해서 제대로된 답이 계속 나오지 않았다.
pop 연산은 새로운 pair를 push하기 전에 수행해줘야 한다.

시간복잡도는 프림 알고리즘의 경우 우선순위 큐와 그래프 구현 방식에 따라 달라진다. 
이 풀이에서는 Heap을 이용한 STL priority_queue와 인접 리스트를 이용했으므로 O(elogv)가 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int check[101];

struct comp { // priority_queue의 비교연산자는 함수가 아닌 구조체 형태로 연산자 오버로딩을 해줘야 한다.
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	int v, e;
	cin >> v >> e;

	vector<vector<pair<int, int> > > edge(v + 1); // 인접 리스트로 구현
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	// 1번 정점을 시작 정점으로 잡고 처리
	int cnt = 1, cost = 0; 
	check[1] = 1;
	for (int i = 0; i < edge[1].size(); i++) {
		pq.push(edge[1][i]);
	}

	while (cnt != v && !pq.empty()) {
		int node = pq.top().first;
		int val = pq.top().second;
		pq.pop();

		if (check[node] == 0) { // 이전에 이미 탐색된 노드가 아닌지 확인
			cost += val;
			check[node] = 1;
			cnt++;

			for (int i = 0; i < edge[node].size(); i++) { // 처리된 노드와 인접한 노드, 간선 정보를 큐에 push
				if (edge[node][i].first != node)
					pq.push(edge[node][i]);
			}
		}
	}

	cout << cost;

	return 0;
}
