/*
정전 이후 다시 시작해아 하는 순서인 작업의 번호를 출력하는 문제.
카카오 '무지의 먹방 라이브' 문제의 변형으로 시뮬레이션으로 풀었다.

시간복잡도는 O(nk)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int task[2001];

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		sum += t;
		task[i + 1] = t;
	}

	int k;
	cin >> k;

	if (sum <= k) { // 정전되기 전에 모든 작업이 처리됨
		cout << -1;

		return 0;
	}

	int idx = 1;
	while (k >= 0) {
		if (task[idx] > 0) { // 아직 처리가 끝나지 않은 작업일 경우
			if (k == 0) // 정전까지 남은 시간이 0이면 해당 작업은 처리되지 못 하고 정전
				break;

			task[idx]--; // 1초씩 작업 처리
			k--; // 정전까지 남은 시간 1초 감소
		}

		if (idx == n)
			idx = 1;
		else
			idx++;
	}

	cout << idx;

	return 0;
}
