/*
오름차순으로 정렬된 두 배열이 주어질 때 두 배열을 합쳐서 오름차순으로 출력하는 문제.
Merge Sort의 분할 정복 과정에서 2개의 정렬된 리스트를 merge하는 단계를 구현하는 문제이다.

시간복잡도는 O(n + m)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, m;
	queue<int> q1;
	queue<int> q2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		q1.push(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		q2.push(num);
	}

	while (!q1.empty() && !q2.empty()) {
		if (q2.front() >= q1.front()) {
			cout << q1.front() << " ";
			q1.pop();
		}
		else {
			cout << q2.front() << " ";
			q2.pop();
		}
	}

	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
	while (!q2.empty()) {
		cout << q2.front() << " ";
		q2.pop();
	}

	return 0;
}
