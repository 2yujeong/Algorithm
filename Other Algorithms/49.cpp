/*
블록을 쌓는 데 사용할 수 있는 블록의 최대 개수를 출력하는 문제.
정면에서 봤을 때의 높이 정보와 오른쪽 측면에서 봤을 때의 높이 정보를 하나씩 비교하여 더 작은 값을 선택한다.
 
시간복잡도는 O(n^2) 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int block[2][11];

	int n, front, right;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> front;

		block[0][i] = front;
	}
	for (int i = 0; i < n; i++) {
		cin >> right;

		block[1][i] = right;
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max += min(block[0][i], block[1][j]);
		}
	}

	cout << max;

	return 0;
}
