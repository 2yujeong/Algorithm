/*
문제 출처 : https://www.acmicpc.net/problem/1676 (백준 온라인 저지)

N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 문제.

2와 5의 곱이 있으면 곱의 뒤에 0이 추가된다.
따라서 n을 소인수분해 했을 때의 2와 5의 개수를 이용하여 문제를 풀 수 있다.
만약 5가 m번 포함된다면 그 앞 순서인 2도 반드시 m번 이상 포함된다.
따라서 소인수분해 시 5의 개수에 따라 결과가 변하므로 반복문을 통해 5로 나누면서 누적합을 구해주면 된다.

시간복잡도는 O(log(5) n)
*/

#include <iostream>
using namespace std;

int main() {
	int a, ans = 0;
	cin >> a;

	for (int i = 5; i <= a; i *= 5) {
		ans += a / i;
	}

	cout << ans << '\n';
}
