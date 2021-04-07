/*
정글의 지도정보가 주어졌을 때 심바가 정글의 모든 토끼를 잡아먹는 데에 걸리는 시간을 출력하는 문제.
심바는 자신의 몸 크기보다 작은 크기의 토끼만 잡아먹을 수 있으며 자신의 몸 크기와 같은 마리수만큼 토끼를 잡아먹으면 몸의 크기가 1 증가한다.
심바는 가장 거리가 가까운 토끼부터 잡아먹으며 거리가 같은 토끼가 여러 마리라면 가장 위에, 가장 오른쪽에 위치한 토끼부터 잡아먹는다.
거리 1은 이동하는 데에 1초가 걸린다.

토끼를 잡아먹는 순서에 대한 규칙이 존재하므로 우선순위 큐를 사용하였다. 
심바가 새로운 토끼를 잡아먹으면 해당 위치로부터 가장 가까운 위치의 토끼를 새로 찾고, 이동 거리가 해당 시점(심바의 맨 처음 위치로부터 현재 위치까지의 이동 거리)을 기준으로 다시 1씩 증가해야 하므로 그 시점부터 BFS를 새로 시작해줘야 한다. 
삼성SW역량테스트 문제로 출제되었다. 

시간복잡도는 토끼를 잡아먹을 때마다 BFS를 새로 시작하므로 토끼의 수 만큼 BFS가 돌게된다. 
토끼의 수가 최대인 n^2 - 1의 경우 각각의 BFS의 시간복잡도를 계산해보면 check배열의 초기화로 인해 탐색 범위와 상관없이 최대 O(n^2)이 걸린다.
따라서 O((n^2 - 1) * n^2) = O(n^4)이지만 memset 함수 호출을 이용하면 실제로는 O(n^4)보다는 더 빠를 것이다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[26][26];
int check[26][26];

class region {
public:
	int x, y, dist; // x좌표, y좌표, 처음 심바의 위치에서 (x, y)까지 오는 데에 걸린 거리(시간)
};

struct comp { // priority_queue의 비교연산자는 함수가 아닌 구조체 형태로 연산자 오버로딩을 해줘야 한다.
	bool operator()(region a, region b) {
		// 거리가 가까울수록 / 위에 있을 수록 / 왼쪽에 있을 수록 우선순위가 높아진다.
		if (a.dist == b.dist) {
			if (a.x == b.x)
				return a.y > b.y;
			return a.x > b.x;
		}
		return a.dist > b.dist;
	}
};

// 가장 가까운 거리에 있는 토끼부터 잡아먹어야 하므로 우선수위 큐 이용
priority_queue<region, vector<region>, comp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) { // 시작점(심바의 처음 위치)
				map[i][j] = 0;
				pq.push({ i,j,0 }); 
			}
		}
	}

	int size = 2, ate = 0, result;

	while (!pq.empty()) { // map 배열 값이 모두 0일 때(더이상 잡아먹을 게 없을 때) pq를 통해 전체탐색을 한 번 진행하고 나면 pq가 다 비워지고 BFS가 끝난다.
		int x = pq.top().x;
		int y = pq.top().y;
		int sec = pq.top().dist;
		pq.pop();

		if (map[x][y] != 0 && map[x][y] < size) { // 심바보다 크기가 작으면 잡아먹는다.
			ate++;
			map[x][y] = 0;

			if (ate == size) { // 현재의 몸 크기와 같은 마리수 만큼 잡아먹으면 몸의 크기 1 증가
				size++;
				ate = 0;
			}

			// 심바가 현재 위치로 오고 나서 새로 탐색을 시작해야 하므로 check 배열과 pq 초기화
			memset(check, 0, sizeof(check)); 
			while (!pq.empty()) {
				pq.pop();
			}

			result = sec; // 현재 위치까지 오는 데에 걸린 시간
		}

		// 1초만에 갈 수 있는 상하좌우 지역부터 탐색하며 pq에 넣는다.
		if (x - 1 >= 0 && map[x - 1][y] <= size && check[x - 1][y] == 0) {
			pq.push({ x - 1, y, sec + 1 });
			check[x - 1][y] = 1;
		}
		if (x + 1 < n && map[x + 1][y] <= size && check[x + 1][y] == 0) {
			pq.push({ x + 1, y, sec + 1 });
			check[x + 1][y] = 1;
		}
		if (y - 1 >= 0 && map[x][y - 1] <= size && check[x][y - 1] == 0) {
			pq.push({ x, y - 1, sec + 1 });
			check[x][y - 1] = 1;
		}
		if (y + 1 < n && map[x][y + 1] <= size && check[x][y + 1] == 0) {
			pq.push({ x, y + 1, sec + 1 });
			check[x][y + 1] = 1;
		}
	}

	cout << result;

	return 0;
}
