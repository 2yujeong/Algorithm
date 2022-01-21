/*
문제 출처 : https://www.acmicpc.net/problem/2075

N * N 크기의 표에 N^2개의 수가 한 칸에 하나씩 채워져 있다.
모든 숫자들은 자신의 윗칸에 있는 수보다 크다.
표에 채워진 숫자들 중 N번째로 큰 수를 구하는 문제.

처음에는 실행시간을 줄이기 위해 문제에서 주어진 '모든 숫자들은 자신의 윗칸에 있는 수보다 크다'는 조건을 활용하는 데에 집중했지만
이 문제는 메모리 제한이 매우 타이트한 문제이기 때문에 실행시간 보다는 메모리 관리에 좀 더 신경써서 풀어야 한다.
이를 위해 항상 일정한 크기를 유지하는 우선순위 큐를 이용하여 풀었다.
먼저 작은 수일수록 top에 가까워지는 MinHeap으로 구현된 우선순위 큐를 선언하고
각 칸의 수를 입력 받을 때마다 큐에 넣어준 뒤, 큐의 사이즈가 N을 넘어가면 큐의 top을 pop해 줌으로써 큐의 크기가 항상 N을 초과하지 않도록 구현했다.
이렇게 하면 큐의 사이즈가 N을 넘을 때마다 현재의 큐에서 가장 작은 수가 pop 되기 때문에
마지막에는 표에서 가장 작은 수부터 N + 1번째로 큰 수들까지 모두 큐에서 pop되고 큐의 top에는 N번째로 큰 수가 남아있게 된다.

시간복잡도는 O(n^2log n)
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			pq.push(num);

			if (pq.size() > n)
				pq.pop();
		}
	}

	cout << pq.top();
	pq.pop();

	return 0;
}
