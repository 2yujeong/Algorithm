/*
SEND+MORE=MONEY 복면산을 구하는 문제.
DFS를 이용한 순열을 응용하여 풀었다.

시간복잡도는 순열이므로 O(nPr) = O(n!)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sendmory[8]; // 정답 배열 - 각 문자에 해당하는 숫자를 저장한 배열
int check[10]; // 각 문자는 서로 다른 숫자이므로 DFS 경로를 구성하는 수 중에 중복이 없게 하기 위한 check 배열

int send() {
	return sendmory[0] * 1000 + sendmory[1] * 100 + sendmory[2] * 10 + sendmory[3];
}

int more() {
	return sendmory[4] * 1000 + sendmory[5] * 100 + sendmory[6] * 10 + sendmory[1];
}

int money() {
	return sendmory[4] * 10000 + sendmory[5] * 1000 + sendmory[2] * 100 + sendmory[1] * 10 + sendmory[7];
}

void dfs(int n) {
	if (n == 8) {
		if (send() + more() == money()) { // 모든 조합에 대해 DFS를 돌려보다가 조건에 맞는 순열을 찾으면
			if (sendmory[0] == 0 || sendmory[4] == 0) // 맨 앞자리 숫자(send의 s / more, money의 m)가 0이면 안 되므로
				return;

			cout << "  " << sendmory[0] << " " << sendmory[1] << " " << sendmory[2] << " " << sendmory[3];
			cout << "\n+ " << sendmory[4] << " " << sendmory[5] << " " << sendmory[6] << " " << sendmory[1];
			cout << "\n----------";
			cout << "\n" << sendmory[4] << " " << sendmory[5] << " " << sendmory[2] << " " << sendmory[1] << " " << sendmory[7];

			exit(0);
		}

		return;
	}

	for (int i = 0; i < 10; i++) { // 1부터 10까지의 순열을 구하기 위한 DFS
		if (check[i] == 0) {
			check[i] = 1;
			sendmory[n] = i;
			dfs(n + 1);
			check[i] = 0;
		}
	}
}

int main() {
	dfs(0);

	return 0;
}
