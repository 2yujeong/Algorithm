/*
문제 출처 : https://www.acmicpc.net/problem/2804 (백준 온라인 저지)

길이가 각각 N, M인 두 단어 A와 B를 교차시켜 크로스워드 퍼즐을 만들려고 한다.
A는 가로로 놓여야 하고, B는 세로로 놓여야 하며 두 단어가 공유하는 글자는 A와 B에 동시에 포함되어 있는 글자여야 한다. 
이러한 글자가 여럿인 경우 A에서 제일 먼저 등장하는 글자를 선택하며 마찬가지로 B에서도 여러 번 등장하면 B에서 제일 처음 나오는 것을 선택한다. 
M x N 형식으로 두 단어가 교차된 형태를 출력하는 문제. 나머지 글자는 '.'로 출력한다.

첫 번째 이중 for문으로 두 단어가 교차되는 지점을 찾고
두 번째 이중 for문을 이용하여 M x N 형태로 정답을 출력한다.
교차 지점의 위치가 a에서는 pos1, b에서는 pos2이면 출력 시 pos2 줄에는 a를 가로로 순서대로, pos1 칸에는 b를 세로로 순서대로 출력해준다.

시간복잡도는 O(nm)
*/ 

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int pos1, pos2;
	for (pos1 = 0; pos1 < a.length(); pos1++) {
		for (pos2 = 0; pos2 < b.length(); pos2++) {
			if (a[pos1] == b[pos2])
				break;
		}

		if (a[pos1] == b[pos2])
			break;
	}

	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (i == pos2)
				cout << a[j];
			else if (j == pos1)
				cout << b[i];
			else
				cout << '.';
		}

		cout << endl;
	}

	return 0;
}
