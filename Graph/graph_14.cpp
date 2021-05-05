/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

n개의 일간의 선후관계가 입력으로 주어지면 위상정렬을 구현하는 문제.

위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘으로 각각의 일의 선후관계를 유지하면서 전체 일의 순서를 짜는 알고리즘이다. 그래프를 이용하여 각 일을 정점으로, 선후관계를 간선으로 표현하며 진입차수를 이용하여 해결한다. 
진입차수란 방향그래프에서 정점 A로 들어오는 간선의 수를 의미하며(A에서 나가는 간선은 포함 X) 여기서는 일 A를 실행하기 위해 선행되어야 하는 일의 수를 의미한다. 

시간복잡도는 진입차수를 1씩 줄이는 작업, 즉 간선을 끊어내는 작업이 모든 간선에 대해 필요하므로 O(E), 입력으로 주어진 일의 순서가 꼬여있지 않다면 모든 정점에 대해 큐에 넣고 간선 처리를 수행하므로 O(V)가 걸린다. 
따라서 총 시간복잡도는 O(V + E)가 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> degree(n + 1, 0); // 각 정점별 진입차수 저장
	vector<vector<int> > v(n + 1); // 인접그래프

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		degree[b]++;
		v[a].push_back(b);
	}

	queue<int> q; // 실행 준비가 된 일들(자신보다 선행되어야 하는 일이 더이상 없는 일들)을 들어온 순서대로 실행하기 위한 큐

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) { // 진입차수가 0이면 자신보다 선행되어야 하는 일이 없으므로 실행 준비가 됐다는 의미에서 큐에 넣는다.
			q.push(i);
		}
	}

	while (!q.empty()) {
		for (int i = 0; i < v[q.front()].size(); i++) { // q.front()에 해당하는 일이 실행되면 
			degree[v[q.front()][i]]--; // 그 일이 자신보다 선행되어야 했던 일들의 진입차수가 하나 감소한다.

			if (degree[v[q.front()][i]] == 0) // 진입차수가 0이 되면 자신보다 선행되어야 했던 일들이 다 실행됐다는 뜻이므로 큐에 넣는다.
				q.push(v[q.front()][i]);
		}

		cout << q.front() << " ";
		q.pop();
	}
	
	return 0;
}
