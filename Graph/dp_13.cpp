/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

1번부터 n번까지의 n명의 회원 중 서로 친구인 회원들의 번호쌍이 주어진다. 
각 회원들은 회장을 뽑기 위해 점수를 받게 되는데, 회원 a가 다른 모든 회원들과 친구인 경우 1점을 받는다.
만약 a가 어느 한 명이라도 직접 친구가 아니라 친구의 친구라면 2점을, 친구의 친구의 친구라면 3점을, ... 이런 식으로 점수를 받게 된다.
점수가 가장 작은 사람들이 회장 후보가 된다고 할 때, 그 점수와 회장 후보의 수, 각 후보들의 번호를 출력하는 문제.

서로 알기 위해 중간에 거치는 사람 수가 많을수록 점수가 늘어남 
-> N : N 최단경로 문제로 생각하고 서로 친구면 간선 비용(가중치)을 1로, 서로 친구가 아니면 무한으로 인접행렬을 생성하여 풀면 된다. 
만약 b가 a의 친구의 친구라면 중간에 1명을 거치므로 인접행렬[b][a]는 무한에서 2로 초기화된다. 
Floyd-Warshall을 이용하여 N : N 최단경로 문제를 풀면, n명의 각 회원별로 자신을 제외한 나머지 회원들과의 비용(알기 위해 거쳐야 하는 사람 수)을 구할 수 있으며 그중 최대값이 그 사람의 점수가 된다. 

시간복잡도는 O(n^3)
Floyd-Warshall 알고리즘과 시간복잡도에 관해서는 dp_12.cpp 참조(https://github.com/2yujeong/Algorithm/blob/master/Graph/dp_12.cpp)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int> > dist(n + 1, vector<int>(n + 1, 50));
	
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	while (1) {
		int a, b;
		cin >> a >> b;

		if (a == -1)
			break;

		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) { // n개의 단계 중 각 k번째 단계에서는 k번 정점을 중간 경로로 이용하는 최단 경로를 찾는다.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	vector<int> result(n + 1, -1);
	int point = 50;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result[i] = max(result[i], dist[i][j]);
		}

		point = min(point, result[i]);
	}

	vector<int> candidate;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (result[i] == point) {
			cnt++;
			candidate.push_back(i);
		}
	}

	cout << point << " " << cnt << "\n";

	for (int i = 0; i < candidate.size(); i++) {
		cout << candidate[i] << " ";
	}
	
	return 0;
}
