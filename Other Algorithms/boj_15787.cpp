/*
문제 출처 : https://www.acmicpc.net/problem/15787 (백준 온라인 저지)

20개의 일렬로 된 좌석이 있는 기차 N개가 은하수를 건너려고 한다.
기차에는 다음과 같은 명령들이 M개 주어진다. 
 1. i x : i번째 기차에(1 ≤ i ≤ N) x번째 좌석에(1 ≤ x ≤ 20) 사람을 태운다.
 2. i x : i번째 기차에 x번째 좌석에 앉은 사람은 하차한다. 
 3. i : i번째 기차에 앉아있는 승객들이 모두 한칸씩 뒤로간다. 20번째 자리에 사람이 앉아있다면 그 사람은 이 명령 후에 하차한다.
 4. i : i번째 기차에 앉아있는 승객들이 모두 한칸씩 앞으로간다. 1번째 자리에 사람이 앉아있다면 그 사람은 이 명령 후에 하차한다.
기차는 1번 기차부터 순서대로 은하수를 지나간다. 
이때 기차가 지나갈 때 승객이 앉은 상태를 목록에 기록하는데 이미 목록에 존재하는 기록이라면 해당 기차는 은하수를 건널 수 없다.
처음 주어지는 기차에는 사람이 아무도 타지 않는다고 할 때 은하수를 건널 수 있는 기차의 수를 구하는 문제.

비트마스킹을 이용하여 간단하게 풀 수 있다.
N개의 기차의 상태를 저장하는 bit 배열을 선언하고
i번째 기차에 대한 명령이 들어오면 bit의 i번째 원소인 bit[i]에 대해 비트 연산을 실행한다.

시간복잡도는 O(nm)
*/

#include <iostream>
#include <vector>
using namespace std;

bool train[1 << 21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> bit;

	int n, m, q;
	cin >> n >> m;
	bit.resize(n + 1);

	while (m--) {
		cin >> q;

		if (q == 1) {
			int i, x;
			cin >> i >> x;
			bit[i] |= (1 << x);
		}
		else if (q == 2) {
			int i, x;
			cin >> i >> x;
			bit[i] &= ~(1 << x);
		}
		else if (q == 3) {
			int i;
			cin >> i;
			bit[i] = (bit[i] << 1);
			bit[i] &= ~(1 << 21);
		}
		else if (q == 4) {
			int i;
			cin >> i;
			bit[i] = (bit[i] >> 1);
			bit[i] &= ~(1 << 0);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!train[bit[i]])
			cnt++;
		train[bit[i]] = true;
	}

	cout << cnt << "\n";
}
