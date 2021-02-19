/*
앞의 풀이의 원리가 잘 이해가지 않아서 for문을 이용하여 다음과 같이 다소 직관적인 방법으로도 풀어보았다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = n / 2; i > 0; i--) { // 2개 이상의 연속된 자연수 -> (2 / n + 1) + (2 / n + 2)부터 n보다 커진다.
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