/*
문제 출처 : https://www.acmicpc.net/problem/2164 (백준 온라인 저지)

1번부터 N번까지 번호가 붙은 N개의 카드가 위에서부터 아래로 오름차순으로 놓여져 있다.
제일 위에 있는 카드를 바닥에 버린 뒤, 그 다음으로 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮기는 작업을 
카드가 한 장만 남을 때까지 반복한다고 할 때 제일 마지막에 남게되는 카드를 구하는 문제.

자료구조 큐를 이용하여 1번부터 N번까지의 카드를 차례로 큐에 넣고
문제에 제시된 과정대로 큐에 카드가 한 장 남을때까지 반복해준다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		q.push(i);

	if (n == 1) 
		cout << n;
	else {
		while (1) {
			q.pop();
			if (q.size() == 1)
				break;
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
	}
}
