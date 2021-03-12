/*
집합을 둘로 나눴을 때 각 부분집합의 합이 같은 경우가 있다면 YES를, 그렇지 않다면 NO를 출력하는 문제. 아마존 인터뷰 문제로 출제되었다.
59번 부분집합 문제를 활용하여 풀었다. 59번 솔루션에 있는 부분집합을 구하기 위한 set 배열과 함께 각 원소 값을 저장하는 배열 element을 이용하였다.
각 부분집합을 구성하는 원소들(Level L + 1에서 set 배열 값이 1인 원소들)의 합과 그 외의 원소들(set 배열 값이 0)의 합이 같으면 둘로 나눠진 부분집합들의 각 합이 같으므로 YES를 출력한다.

시간복잡도는 O(2^n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int set[11];
int element[11];
int flag;

void find_set(int l, int n) {
	if (flag == 1)
		return;

	if (l == n + 1) {
		int sum1 = 0, sum2 = 0;

		for (int i = 1; i <= n; i++) {
			if (set[i] == 1)
				sum1 += element[i];
			else
				sum2 += element[i];
		}

		if (sum1 == sum2)
			flag = 1;
		else
			flag = 0;

		return;
	}

	set[l] = 1;
	find_set(l + 1, n);
	set[l] = 0;
	find_set(l + 1, n);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> element[i];
	}

	find_set(1, n);

	if (flag == 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
