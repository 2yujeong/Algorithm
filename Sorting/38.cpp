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
