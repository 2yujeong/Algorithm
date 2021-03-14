/*
집합의 원소와 +, - 연산을 이용하여 특정 수를 만드는 경우의 수를 구하는 문제.
노드 하나 당 3개의 자식 노드를 가지는 트리를 구현하여 해결한다. 
3개의 자식 노드는 각각 부모 노드에 해당하는 집합의 원소가 식에 더해질지(+), 빼질지(-), 식에 아예 참여하지 않을지에 대한 경우를 의미하며
트리의 n번째 레벨은 집합의 첫 번째부터 n번째까지의 원소들에 관한 모든 연산 결과의 조합을 의미한다.

시간복잡도는 지수 시간의 시간복잡도를 갖는다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int element[11];
int n, m, answer = 0;

void find_case(int l, int val) {
	if (l == n + 1) {
		if (val == m)
			answer++;

		return;
	}

	find_case(l + 1, val + element[l]);
	find_case(l + 1, val - element[l]);
	find_case(l + 1, val);
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> element[i];
	}

	find_case(1, 0);

	cout << answer;

	return 0;
}
