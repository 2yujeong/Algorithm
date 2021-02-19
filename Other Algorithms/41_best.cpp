/*
입력 N에 대해 2개 이상의 연속된 자연수의 합으로 표현하는 방법의 가짓수를 출력하는 문제
효율적인 문제 풀이 방법이 쉽게 떠오르지 않아서 이상적인 정답 코드를 참고했다.이 풀이가 왜 성립되는지는 아직 이해 못 했지만 인터뷰에서는 직관적인 풀이보다 이러한 풀이가 더 좋은 인상을 남긴다고 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a, b = 2, cnt = 0;
	a = n - 1;

	while (a > 0) {
		a -= b; // n에서 1, 2, ..., b까지를 뺀다.
		if (a % b == 0) { // 뺀 수가 b로 나누어 떨어지면 n은 a / b + 1부터 a / b + b까지 b개의 연속된 수의 합으로 표현된다.
			for (int j = 1; j < b; j++) {
				cout << a / b + j << " + ";
			}
			cout << a / b + b << " = " << n << endl;
			cnt++;
		}
		b++; // b는 2부터 n - 1 - 2 - ... - b가 0보다 작아질 때까지 1씩 증가
	}

	cout << cnt;

	return 0;
}