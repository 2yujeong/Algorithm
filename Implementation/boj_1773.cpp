/*
문제 출처 : https://www.acmicpc.net/problem/1773 (백준 온라인 저지)

N명의 학생들이 각자의 일정한 주기에 따라 폭죽을 터뜨린다. 
초 단위로 터지는 폭죽을 관찰한다고 할 때 총 몇 초 동안 폭죽이 터지는 것을 볼 수 있는지 구하는 문제.

폭죽쇼가 끝나는 시간인 C의 범위가 크지 않으므로, 각 시간 별로(초 단위) 폭죽이 몇 번 터졌는지 저장하는 배열 v를 선언하였다.
i초에 폭죽이 한 번 터질 때마다 v[i]의 값에 1을 더해주는 방식으로 v를 업데이트 한다.
마지막에는 총 관찰 시간을 구하는데 여러 명의 학생이 동시에 터뜨린 폭죽 역시 1초 동안만 관찰한 것으로 세기 때문에 
정확히 몇 번 터졌는지와는 상관 없이 1번 이상만 터지면 정답에 1을 더해준다.

시간복잡도는 O(nc)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, c, cnt = 0;
	cin >> n >> c;

	vector<int> v(c + 1, 0);

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		for (int j = temp; j <= c; j += temp) {
			v[j]++;
		}
	}

	for (int i = 1; i < v.size(); i++) {
		if (v[i] > 0)
			cnt++;
	}

	cout << cnt;

	return 0;
}
