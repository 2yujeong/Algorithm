/*
문제 출처 : https://www.acmicpc.net/problem/3062 (백준 온라인 저지)

수 124를 뒤집으면 421이 되고 124와 421을 합하면 좌우가 대칭인 수인 545가 된다. 
이와 같이 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되면 YES를, 아니면 NO를 출력하는 문제.

정수-문자열 간의 형 변환을 이용하면 어렵지 않게 풀 수 있다.

시간복잡도는 O(n), n은 입력받은 수를 문자열로 변환했을 때의 길이
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		string reverse = "";
		for (int i = s.size() - 1; i >= 0; i--) {
			reverse += s[i]; // 입력 받은 수 s를 뒤집어서 reverse에 저장
		}

		int sum = stoi(s) + stoi(reverse); // 두 수의 합 구하기
		string strSum = to_string(sum); // 두 수의 합을 string으로 변환
		
		int isAsym = 0; // 비대칭인지 아닌지 체크하기 위한 변수
		for (int i = 0; i < strSum.length() / 2; i++) {
			if (strSum[i] != strSum[strSum.length() - 1 - i]) { // 비대칭일 경우
				isAsym = 1;
				break;
			}
		}

		if (isAsym)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}
