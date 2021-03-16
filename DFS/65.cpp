/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#

DFS를 이용하여 미로를 탈출하는 경로의 가지수를 출력하는 문제.
상하좌우로만 움직이므로 if문을 이용하여 상하좌우 4개의 경우에 대해서만 다음 탐색을 진행하였다. 이미 방문한 노드의 경우 check 배열을 따로 사용하는 대신 map의 값을 1로 변경함으로써 다시 탐색하지 않도록 해주었다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int map[8][8];
int answer = 0;

void DFS(int x, int y) { // 재귀함수가 스택 구조를 이용하므로 재귀함수 대신 스택으로 구현해도 된다.
	if (x == 7 && y == 7) {
		answer++;
		return;
	}

	if (x - 1 > 0 && map[x - 1][y] == 0) {
		map[x - 1][y] = 1;
		DFS(x - 1, y);
		map[x - 1][y] = 0;
	}
	if (x + 1 < 8 && map[x + 1][y] == 0) {
		map[x + 1][y] = 1;
		DFS(x + 1, y);
		map[x + 1][y] = 0;
	}
	if (y - 1 > 0 && map[x][y - 1] == 0) {
		map[x][y - 1] = 1;
		DFS(x, y - 1);
		map[x][y - 1] = 0;
	}
	if (y + 1 < 8 && map[x][y + 1] == 0) {
		map[x][y + 1] = 1;
		DFS(x, y + 1);
		map[x][y + 1] = 0;
	}
}

int main() {
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> map[i][j];
		}
	}

	map[1][1] = 1;
	DFS(1, 1);

	cout << answer;

	return 0;
}
