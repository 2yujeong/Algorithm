/*
1번부터 7번까지의 노드로 구성된 이진트리를 전위순회 / 중위순회 / 후위순회 방식으로 출력하는 코드
자식이 여러 개인 트리에서는 전위순회와 후위순회만 가능하다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

void traversal(int v) {
	if (v > 7)
		return;
	else {
		cout << v; // Pre-order
		traversal(v * 2);
//		cout << v; // In-order
		traversal(v * 2 + 1);
//		cout << v; // Post-order
	}
}

int main() {
	traversal(1);

	return 0;
}
