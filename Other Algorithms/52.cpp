/*
Ugly Number : 소인수가 2 or 3 or 5로만 이루어진 수

시간복잡도는 O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n); // 첫 번째부터 n번째까지의 Ugly Number를 순서대로 담을 vector
	v[0] = 1; // 1을 Ugly Numbers의 첫 번째 수로 한다.

	int p2 = 0, p3 = 0, p5 = 0, min = 10; // 3개의 포인터 사용
	for (int i = 1; i < n; i++) {
		// 오름차순으로 담으므로 셋 중 가장 작은 수부터 배열에 넣고 포인터 하나 증가
		if (v[p2] * 2 > v[p3] * 3) {
			if (v[p3] * 3 > v[p5] * 5) {
				min = v[p5] * 5;
				p5++;
			}
			else {
				min = v[p3] * 3;
				p3++;
			}
		}
		else {
			if (v[p2] * 2 > v[p5] * 5) {
				min = v[p5] * 5;
				p5++;
			}
			else {
				min = v[p2] * 2;
				p2++;
			}
		}

		v[i] = min;

		// 겹치는 수가 배열에 들어가지 않도록 처리
		if (v[p2] * 2 == min)
			p2++;
		if (v[p3] * 3 == min)
			p3++;
		if (v[p5] * 5 == min)
			p5++;
	}

	cout << v.back();

	return 0;
}
