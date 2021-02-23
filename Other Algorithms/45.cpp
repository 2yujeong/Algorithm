/*
복잡하지 않은 시뮬레이션 문제이다. 최대 입력 크기(n <= 1,000) 만큼의 배열을 이용하였으며 제외된 왕자 번호에 해당하는 index의 배열 값은 -1로 초기화해주었다. 

시간복잡도는 O(nk)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prince[1001];

int main() {
	int n, k;
	cin >> n >> k;

	int num = 0, cnt = n, idx = 1;
	while (cnt > 1) {
		if (prince[idx] != -1) { // 아직 제외되지 않은 왕자라면
			num++; // 숫자를 외친다.

			if (num == k) { // k를 외친 경우
				prince[idx] = -1; // k를 외친 왕자를 제외시키고
				cnt--; // 남아있는 왕자의 수 감소
				num = 0; // 다음 왕자부터는 다시 1부터 수를 외친다.
			}
		}

		if (idx == n)
			idx = 1;
		else
			idx++;
	}

	for (int i = 1; i < n + 1; i++) {
		if (prince[i] != -1) { // 남아있는 1명의 왕자를 찾아 출력
			cout << i;

			return 0;
		}
	}
}
