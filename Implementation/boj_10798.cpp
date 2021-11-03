/*
최대 15 길이의 단어 5개가 한 줄에 하나씩 입력될 때 주어진 입력을 세로로 읽은 순서대로 출력하는 문제.
세로로 읽을 때 해당 자리에 글자가 없으면 읽지 않고 그 다음 글자를 계속 읽는다.

이중 for문과 문자열을 이용하여 풀 수 있는 간단한 구현 문제이다.

시간복잡도는 단어의 개수와 최대 길이에 의존하지만 이 문제에서는 입력 범위가 제한되어 있으므로 O(1)
*/

#include <iostream>
#include <string>
using namespace std;

string arr[5];

int main() {
	for (int i = 0; i < 5; i++) {
		string s;
		getline(cin, s);

		arr[i] = s;
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (j < arr[i].length())
				cout << arr[i][j];
		}
	}

	return 0;
}
