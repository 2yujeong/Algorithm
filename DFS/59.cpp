/*
1부터 N까지의 수로 이루어진 집합의 모든 부분집합을 출력하되 재귀함수와 이진트리 전위순회를 이용한다. 
집합의 각 원소값들을 인덱스로 하는 배열을 생성하고 루트에서부터 전위순회 순서를 따라 내려가며 재귀를 진행하는 방식으로 풀었다.
왼쪽 자식으로 내려갈 때는 부모 레벨(루트부터 Level 1) 인덱스의 배열 값을 1로, 오른쪽 자식으로 내려갈 때는 0으로 초기화하며 마지막 레벨(Level N + 1)까지 내려가면 배열 값이 1인 인덱스들의 집합이 부분집합이 되고 차례로 출력해주면 된다. 
MS 인터뷰 문제로 출제되었다.

시간복잡도는 모든 조합에 대해 탐색하므로 O(2^n)의 지수 시간이 걸린다. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int set[11];

void traversal(int l, int n) {
	if (l == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (set[i] == 1)
				cout << i << " ";
		}
		cout << endl;

		return;
	}

	set[l] = 1;
	traversal(l + 1, n);
	set[l] = 0;
	traversal(l + 1, n);
}

int main() {
	int n;
	cin >> n;

	traversal(1, n);

	return 0;
}
