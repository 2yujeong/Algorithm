/*
스택을 이용하여 N을 K진수로 변환 출력하는 문제.
나누기와 나머지 연산을 이용한 진수 변환 과정을 그대로 코드로 구현하였다.

시간복잡도는 O(log(k)n)
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	stack<int> s;

	while (n != 0) {
		s.push(n % k);
		n /= k;
	}
	
	while (!s.empty()) {
		if (s.top() < 10)
			cout << s.top();
		else
			cout << (char)(s.top() + 55);

		s.pop();
	}

	return 0;
}
