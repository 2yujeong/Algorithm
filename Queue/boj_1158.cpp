/*
문제 출처 : https://www.acmicpc.net/problem/1158 (백준 온라인 저지)

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
이때 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 할 때 입력 N, K에 대한 요세푸스 순열을 구하는 문제.

이전에 풀었던 공주 구하기 문제와 비슷하다.
먼저 1부터 n까지의 수를 차례로 큐에 넣어놓고, 큐가 완전히 빌 때까지 큐의 front를 pop하는 과정을 반복한다.
이 과정에서 pop한 수가 만약 k번째 수가 아니라면 다시 큐의 뒤에 넣어주고, k번째 수라면 큐에서 아예 제거한다.

시간복잡도는 O(nk)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int num = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (num == k) {
			result.push_back(temp);
			num = 1;
			continue;
		}
		q.push(temp);
		num++;
	}

	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[n - 1] << ">";

	return 0;
}
