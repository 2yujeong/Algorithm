/*
Max-Heap 대신 Min-Heap을 이용한 우선순위 큐를 이용한다.
다음과 같이 오름차순으로 우선순위 큐를 선언해줘도 되고 삽입할 때 - 부호로 바꿔서 넣은 뒤 top을 출력할 때는 다시 - 부호를 붙여서 원래의 수를 출력해주는 방식으로 구현해도 된다.
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> > pq;

	while (true) {
		int n;
		scanf_s("%d", &n);

		if (n == 0) {
			if (pq.empty())
				printf("-1\n");
			else
				printf("%d\n", pq.top());

			pq.pop();
		}
		else if (n == -1)
			break;
		else
			pq.push(n);
	}

	return 0;
}
