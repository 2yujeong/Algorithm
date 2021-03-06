/*
재귀함수를 이용하여 n을 이진수로 변환 출력하였다.

시간복잡도는 O(log(k)n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

void binaryNum(int n) {
	if (n == 0)
		return;
	else {
		binaryNum(n / 2);
		cout << n % 2;
	}
}

int main() {
	int n;
	cin >> n;

	binaryNum(n);

	return 0;
}
