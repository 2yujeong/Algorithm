/*
자식 노드를 탐색하러 내려갈 때마다 set 배열을 초기화하고 마지막 레벨에서 set 배열을 탐색하는 방식보다는 
element 배열 값을 이용하여 내려갈 때마다 더하거나(set[l] = 1 대신) 빼주면(set[l] = 0 대신) 마지막 레벨의 for문이 필요가 없어서 속도가 조금 더 향상된다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int element[11];
int flag = 0, total = 0;

void find_set(int l, int n, int sum) {
	if (flag == 1)
		return;

	if (l == n + 1) {
		if (sum == (total - sum))
			flag = 1;

		return;
	}

	find_set(l + 1, n, sum + element[l]);
	find_set(l + 1, n, sum);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> element[i];
		total += element[i];
	}

	find_set(1, n, 0);

	if (flag == 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
