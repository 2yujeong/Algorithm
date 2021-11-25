/*
문제 출처 : https://www.acmicpc.net/problem/2696 (백준 온라인 저지)

어떤 수열을 읽고, 홀수 번째 수를 읽을 때마다 지금까지 입력 받은 값의 중앙값을 출력하는 문제.

각각 오름차순 / 내림차순으로 저장되는 2개의 우선순위 큐를 이용하여 풀 수 있다.
입력되는 값이 10개라고 할 때, 값이 작은 순으로 1번째부터 5번째까지의 수들은 max 큐에, 
나머지 6번째부터 10번째까지의 수들, 즉 max 큐에 저장된 5개의 수들보다 큰 수들은 min 큐에 저장한다.
이렇게 구현하면 마지막에 max 큐의 top이 중앙값이 된다.
수들을 오름차순으로 정렬하고 절반을 기준으로 두 그룹으로 나눴을 때, 값이 작은 그룹에서 가장 큰 값이 중앙값이 되는 것과 같은 원리이다.

시간복잡도는 O(mlog m)
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int m;
		cin >> m;

		priority_queue<int> max_q;
		priority_queue<int, vector<int>, greater<int>> min_q;
		vector<int> result;

		for (int i = 1; i <= m; i++) {
			int num;
			cin >> num;

			if (max_q.size() == min_q.size())
				max_q.push(num);
			else
				min_q.push(num);

			if (!min_q.empty() && max_q.top() > min_q.top()) {
				int temp1 = min_q.top();
				int temp2 = max_q.top();

				min_q.pop();
				max_q.pop();

				min_q.push(temp2);
				max_q.push(temp1);
			}

			if (i % 2 == 1)
				result.push_back(max_q.top());
		}

		cout << result.size() << "\n";

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
			
			if ((i + 1) % 10 == 0)
				cout << "\n";
		}
	}

	return 0;
}
