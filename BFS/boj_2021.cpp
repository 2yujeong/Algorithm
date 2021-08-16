/*
문제 출처 : https://www.acmicpc.net/problem/2021 (백준 온라인 저지)

어떤 도시의 지하철 노선에 대한 정보가 주어졌을 때, 출발지에서 목적지까지의 최소 환승 경로를 구하는 문제.
실제 경로를 구할 필요는 없고, 환승 횟수만 구하면 된다.

노선을 기준으로 각각의 노선이 지나는 모든 역들을 담은 lines 배열과
역을 기준으로 각각의 역을 지나는 모든 노선들을 담은 stations 배열을 이용하여 BFS 방식으로 풀었다.
먼저 stations 배열을 이용하여 출발역 A를 지나는 모든 노선들에 대해 다음과 같은 탐색을 진행한다.
각 노선들의 경로를 lines 배열을 이용해 차례로 탐색하며 도착역을 포함하고 있는 노선이 없는지 찾고,
만약 그러한 노선이 없다면 각 노선에서 지나는 각각의 역을 기준으로 환승할 수 있는 모든 다른 노선들을 찾아 큐에 넣는다.
이때 다른 노선으로 환승한다는 의미로 카운트 값(= 환승 횟수)을 1 증가시켜 준다.
BFS를 진행할 때는 중복 탐색이 발생하면 안 되므로 체크배열을 잘 활용해야 한다. 
stations 배열과 lines 배열에 대해 각각의 체크 배열을 활용하지 않으면 시간 초과, 메모리 초과가 난다.

시간복잡도는 O(nm), n과 m은 각각 역의 개수와 노선의 개수
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<vector<int> > stations(n + 1); // n개의 역별로 해당 역을 지나는 노선들을 담기 위한 배열
	vector<vector<int> > lines(l); // l개의 노선 별로 해당 노선이 지나는 역들을 담기 위한 배열
	vector<int> check_station(n + 1, 0);
	vector<int> check_line(l, 0);

	for (int i = 0; i < l; i++) {
		int temp;

		while (1) {
			cin >> temp;

			if (temp == -1)
				break;

			stations[temp].push_back(i);
			lines[i].push_back(temp);
		}
	}

	int src, dst;
	cin >> src >> dst;

	queue<pair<int, int> > q; // 출발역으로부터 출발하여 거치는 모든 노선들과 해당 노선으로 갈아타기까지의 환승 횟수를 담는 큐

	for (int i = 0; i < stations[src].size(); i++) {
		q.push({ stations[src][i], 0 }); // 출발역을 지나는 모든 노선들을 큐에 담는다. 출발역에서 지하철을 탈 때는 최초 탑승이므로 환승 횟수가 0이다.
		check_line[stations[src][i]] = 0; // 이 노선들은 이미 한 번 큐에 담겼으므로 체크 배열 값을 1로 set
	}

	while (!q.empty()) { // BFS 진행
		int line = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < lines[line].size(); i++) { // 현재 거치는 노선이 지나는 모든 역들에 대해 탐색 진행
			int station = lines[line][i];

			if (station == dst) { // 노선이 지나는 역들 중 도착역이 있다면 프로그램 종료
				cout << cnt;

				return 0;
			}

			if (check_station[station] == 0) { // 아직 탐색된 적 없는 역이라면 
				for (int j = 0; j < stations[station].size(); j++) { // 그 역을 지나는 모든 노선들을 큐에 담고, 환승했다는 의미로 카운트 값 + 1
					if (check_line[stations[station][j]] == 0) { // 이미 앞서 탄 적 있는(큐에 들어간 적 있는) 노선은 다시 큐에 넣지 않는다.
						q.push({ stations[station][j], cnt + 1 });
						check_line[stations[station][j]] = 1;
					}
				}

				check_station[station] = 1;
			}
		}
	}

	cout << -1;

	return 0;
}
