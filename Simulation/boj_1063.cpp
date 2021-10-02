/*
문제 출처 : https://www.acmicpc.net/problem/1063 (백준 온라인 저지)

8*8크기의 체스판에 왕과 돌이 하나씩 있다.
체스판에서 말의 위치는 열을 상징하는 알파벳과 행을 상징하는 숫자로 나타내며 체스판의 왼쪽 아래 코너는 A1이다킹은 R, L, B, T, RT, RB, LT, LB 방향으로 한 번에 한 칸씩 움직일 수 있으며
킹이 움직인 위치가 돌이 있던 위치와 겹치면 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
킹과 돌의 마지막 위치를 구하는 문제.

킹의 위치를 나타내는 변수 king_col, king_row와 돌의 위치를 나타내는 변수 stone_col, stone_row를 선언하고
입력에 따라 시뮬레이션 해주면 되는 문제이다.
이동방향이 입력으로 주어질 때는 입력의 길이가 1일 수도 있고 2일 수도 있기 때문에 string의 getline을 이용하여 받아주었다.
참고로 첫째줄에 킹과 돌의 위치, 움직이는 횟수 N과 함께 끝에 엔터가 입력되면
버퍼에 엔터가 남아서 getline이 이 엔터를 받게 된다.
따라서 getline 사용 전 get.ignore() 등으로 버퍼를 비워줘야 한다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<char, int> moving(string s, char col, int row) {
	if (s[0] == 'B')
		row--;
	else if (s[0] == 'T')
		row++;
	else if (s[0] == 'R') {
		col++;

		if (s.length() != 1) {
			if (s[1] == 'B')
				row--;
			else
				row++;
		}
	}
	else {
		col--;

		if (s.length() != 1) {
			if (s[1] == 'B')
				row--;
			else
				row++;
		}
	}

	return { col, row };
}

int main() {
	char king_col, stone_col;
	int king_row, stone_row, n;
	cin >> king_col >> king_row >> stone_col >> stone_row >> n;

	cin.ignore(); // 버퍼를 비워주지 않으면 Enter가 버퍼에 남아서 getline으로 입력된다.

	for (int i = 0; i < n; i++) {

		string s;
		getline(cin, s);

		pair<char, int> king_loc = moving(s, king_col, king_row);
		pair<char, int> stone_loc = { stone_col, stone_row };

		if (king_loc.first == stone_col && king_loc.second == stone_row)
			stone_loc = moving(s, stone_col, stone_row);

		if (king_loc.first >= 'A' && king_loc.first <= 'H' && stone_loc.first >= 'A' && stone_loc.first <= 'H'
			&& king_loc.second >= 1 && king_loc.second <= 8 && stone_loc.second >= 1 && stone_loc.second <= 8) {
			king_col = king_loc.first;
			king_row = king_loc.second;
			stone_col = stone_loc.first;
			stone_row = stone_loc.second;
		}
	}

	cout << king_col << king_row << endl;
	cout << stone_col << stone_row;

	return 0;
}
