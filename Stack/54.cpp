/*
하나의 스택을 이용하여 올바른 괄호인지 판별하는 문제.

(참고) 문자열 입력을 받으면서 string형 변수 처리와 관련하여 std::string NULL 문자에 관해 헷갈리는 부분을 찾아 정리하였다.
-> std::string은 문자열을 실제로 메모리에 저장할 때는 '\0'(NULL)을 포함하지만 개념상 \0에 대한 접근을 허용하지 않는다(ex - operator[]를 통해 \0이 저장된 인덱스에 접근하려고 하면 out_of_range가 발생). 
std::string의 NULL은 NULL로 끝나는 문자열과의 호환성을 위해 메모리에 저장될 뿐 문자열의 길이를 계산할 때는 쓰이는 등의 다른 역할은 하지 않는다. 
string 변수에 문자열이 저장될 때 문자열의 길이는 따로 저장되기 떄문에 '\0'를 포함한 문자열의 길이가 출력되지 않고 입력된 문자열의 길이만 출력된다.
-
참고 답변 출처 : https://hashcode.co.kr/questions/5777/c-string-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%97%90-%EB%AC%B8%EC%9E%90%EC%97%B4%EC%9D%84-%EC%A0%80%EC%9E%A5%ED%95%A0-%EB%95%8C%EB%8A%94-%EB%84%90%EB%AC%B8%EC%9E%90%EA%B0%80-%EC%97%86%EB%82%98%EC%9A%94

시간복잡도는 O(n)
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	string bracket;
	cin >> bracket;

	stack<char> s;

	for (int i = 0; i < bracket.size(); i++) { // 또는 조건부에 bracket[i] != '\0'
		if (bracket[i] == '(')
			s.push(bracket[i]);
		else {
			if (s.empty()) {
				cout << "NO";

				return 0;
			}
			s.pop();
		}
	}

	if (s.empty())
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
