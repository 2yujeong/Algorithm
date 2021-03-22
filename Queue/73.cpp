/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

Max-Heap 구조로 되어있는 우선순위 큐를 이용하여 연산 결과를 출력하는 문제.

참고 : Map-Heap은 완전이진트리 형태로 구현된 자료구조로 부모 노드의 값이 자식 노드의 값보다 항상 커야 하기 때문에 큰 값은 root에 저장되어 있다. 값이 Heap에 삽입될 때는 말단부터 삽입되어 UpHeap을 진행하고, 최댓값(root)을 힙에서 꺼낼 때는 맨 아래 오른쪽에 저장되어 있던 노드의 값이 루트에 복사되며 해당 노드는 삭제된다. 루트에 복사된 값은 DownHeap을 진행하며 Max-Heap 구조를 찾아간다.

시간복잡도는 우선순위 큐의 삽입, 삭제 연산을 생각했을 때 O(logn)
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> pq;

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
