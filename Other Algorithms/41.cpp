/*
���� Ǯ���� ������ �� ���ذ��� �ʾƼ� for���� �̿��Ͽ� ������ ���� �ټ� �������� ������ε� Ǯ��Ҵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = n / 2; i > 0; i--) { // 2�� �̻��� ���ӵ� �ڿ��� -> (2 / n + 1) + (2 / n + 2)���� n���� Ŀ����.
		int j = i + 1, sum = i;
		while (sum < n) {
			sum += j++;
			if (sum == n) {
				for (int k = i; k < j - 1; k++) {
					cout << k << " + ";
				}
				cout << j - 1 << " = " << n << endl;
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}