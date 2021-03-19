/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

한 번의 점프로 앞으로 1칸 / 뒤로 1칸 / 앞으로 5칸을 이동할 수 있을 때 현재 위치 S에서 송아지의 위치 E까지 가는 데에 필요한 최소 점프 횟수를 구하는 문제.

시간복잡도는 좌표의 범위에 의존하므로 좌표 범위가 1부터 n까지라고 하면 O(n)
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dist[10001];

int main() {
	int s, e;
	cin >> s >> e;

	memset(dist, -1, sizeof(dist));
	dist[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int temp = q.front();

		if (temp + 1 <= 10000 && dist[temp + 1] == -1) { // 앞으로 1칸 이동
			if (temp + 1 == e) { // 앞으로 1칸 이동한 위치가 송아지의 위치이면
				cout << dist[temp] + 1; // 여기(temp)까지 오는 데 실행한 점프 횟수 + 1칸 앞으로 한 번 점프 = 총 점프 횟수 출력
				break; 
			}

			dist[temp + 1] = dist[temp] + 1; // temp + 1 위치까지 오는 데에 필요한 점프 횟수 dist에 기록
			q.push(temp + 1); // 아직 답을 찾지 못 했으므로 큐에 넣고 BFS 계속 진행
		}
		if (temp - 1 >= 1 && dist[temp - 1] == -1) { // 뒤로 1칸 이동
			if (temp - 1 == e) {
				cout << dist[temp] + 1;
				break;
			}

			dist[temp - 1] = dist[temp] + 1;
			q.push(temp - 1);
		}
		if (temp + 5 <= 10000 && dist[temp + 5] == -1) { // 앞으로 5칸 이동
			if (temp + 5 == e) {
				cout << dist[temp] + 1;
				break;
			}

			dist[temp + 5] = dist[temp] + 1;
			q.push(temp + 5);
		}

		q.pop();
	}

	return 0;
}
