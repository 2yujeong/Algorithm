/*
문제 출처 : https://www.acmicpc.net/problem/2455 (백준 온라인 저지)

4개의 정차역을 지나는 기차 내에 사람이 가장 많을 때의 사람 수를 구하는 문제.
1번부터 4번까지의 정차역을 지날 때마다 내린 사람 수와 탄 사람 수가 각각 주어진다.
기차에 탑승 중인 사람 수를 저장하는 total 변수를 선언하고
4개의 역마다 내린 사람 수는 빼고 탄 사람 수는 더해가며 최대값을 찾는다.

시간복잡도는 O(n), n은 정차역의 수
*/

#include <iostream>

using namespace std;

int main() {
	int n, m;
	int total = 0, max = -1;

	for (int i = 0; i < 4; i++) {
		cin >> n >> m;
		total -= n;
		total += m;

		if (max < total)
			max = total;
	}

	cout << max;

	return 0;
}
