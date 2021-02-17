/*
�Էµ� N���� ����(���м���) �� 3���� ������ ����ϴ� ����. algorithm�� ���� �˰��� sort()�� ����Ͽ� ���� Ǯ����.

���� : stl�� ���� �˰����� ��Ȯ�� �����ڸ� quick sort�� �ƴ� intro sort �˰����� ����Ѵ�.
intro sort�� quick sort�� ������ �˰������� �־��� ��쿡�� O(nlogn)�� �����ϸ� �� ����� ���� �˰��� �߿��� ���� ������.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;

		v.push_back(score);
	}

	sort(v.begin(), v.end(), greater<int>());

	int cnt = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] != v[i + 1]) {
			cnt++;

			if (cnt == 3) {
				cout << v[i + 1];
				break;
			}
		}
	}

	return 0;
}