/*
Floyd-Warshall 알고리즘을 이용하여 모든 도시에서 모든 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 All-Pairs Shortest Paths 문제.
N : N 최단경로 문제로 1 : N 문제(ex - 다익스트라 알고리즘)를 N번 풀어서 O(nmlog n)에 해결할 수도 있지만 다이나믹 프로그래밍(Floyd-Warshall 알고리즘 방식)을 이용하면 O(n^3)에 풀 수 있다.
반복문마다 인접 여부를 묻는 연산이 필요하기 때문에 인접행렬로 구현해야 areAdjacent() 연산이 O(1)에 실행되어 성능이 가장 빠르다.

[Floyd-Warshall 알고리즘]
Floyd-Warshall 알고리즘은 다이나믹 프로그래밍을 이용하여 Transitive Closure를 얻을 때 쓰인다.
* Transitive Closure : 
알고리즘 동작은 다음과 같다.
1. 모든 정점들은 1번부터 n번까지의 번호로 관리한다.
2. Floyd-Warshall 알고리즘은 1번부터 n번까지 총 n개의 단계로 구성된다. 
- 각각의 단계를 k번째 단계라고 하면, k번째 단계에서는 1번부터 k번까지의 정점들만 중간단계로 이용해서 갈 수 있는 모든 길을 찾는다.
- k번 정점에 도달할 수 있는 모든 인접한 정점들(i->k)과 k번째 정점으로부터 도달할 수 있는 정점들(k->j) 간에 간선을 추가한다(i->j).
3. 이 알고리즘을 All-Pairs Shortest Paths 문제에 적용 
-> k번 정점을 중간단계로 거치는 간선을 추가할 때, 비용을 비교하여 기존의 경로보다 k번 정점을 거치는 경로가 더 적은 비용이면 인접행렬을 업데이트 하고 그렇지 않으면 업데이트 하지 않는다.

시간복잡도는 모든 i, j쌍에 대해 총 n단계를 진행하므로(3중 for문) O(n^3)이 걸리지만 그래프가 Sparse해서 인접 행렬에 0이 많다면 평균 연산 속도가 굉장히 빨라진다. 
->인접행렬에 0이 많아서 k->j 경로가 존재하는 경우가 상수 개(C)인 경우 edge를 삽입하는 연산(i행 j열에 1을 쓰는 연산)도 상수 번만 일어나므로 O(Cn^2)에 실행될 수 있다.
*/

 #include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > dist(n + 1, vector<int>(n + 1, 2000));
	// dist[i][j] = i에서 j로 가는 데 드는 최소비용
	// 아직 도로정보를 입력 받기 전이므로 경로가 존재하지 않는다는 의미에서 Max값(2000)으로 초기화
	// 최단경로를 찾을 때마다 값을 업데이트 하면 된다. (계속해서 Min 값을 찾아 값을 업데이트 한다는 점에서 냅색 알고리즘과 비슷)
	// 공간복잡도는 O(n^2)

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0; // 자기자신으로 가는 최단경로는 0
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = c; // 입력 받은 도로정보로 초기화
	}

	for (int k = 1; k <= n; k++) { // n개의 단계 중 각 k번째 단계에서는 k번 정점을 중간 경로로 이용하는 최단 경로를 찾는다.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		// 각 k단계가 끝난 상황에서의 dist 배열은 정점 k를 거쳐가는 i->j 경로를 포함한 이제까지의 모든 i->j 경로들(= 1번부터 k번까지의 정점들만 중간경로로 활용한 경로들) 중에서 최단경로의 길이를 저장한다.
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] < 2000)
				cout << dist[i][j] << " ";
			else
				cout << "M ";
		}
		cout << "\n";
	}

	return 0;
}
