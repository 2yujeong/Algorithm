/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67257 (프로그래머스 Level 2)

수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 가장 큰 숫자를 리턴하는 문제.
연산자는 +, -, *로만 이루어져 있다.

주어진 식을 파싱해서 등장 순서대로 피연산자는 num 배열에, 연산자는 op 배열에 담아주었다.
연산자 우선순위를 정하고 op 배열의 앞에서부터 가장 높은 우선순위의 연산자와 동일한 연산자인지 확인하고 동일하다면 계산을 진행한다.
동일하지 않다면 다음 연산자로 넘어간다.
이러한 과정을 가장 높은 우선순위의 연산자부터 가장 낮은 우선순위의 연산자까지 진행한다.
연산자 우선순위의 경우 총 6가지의 우선순위를 정의할 수 있다.
여기선 순열을 구하기 위한 dfs를 이용하였지만 간단하게 6가지 경우를 직접 정의하는 방법도 있고 next_permutation을 활용할 수도 있다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str; // expression을 전역 변수로 저장하기 위한 변수
long long answer = 0;

// DFS 진행을 위한 변수들
string oper = "+-*";
vector<int> check(3, 0);
vector<char> priority(3);

vector<long long> num; // expressions의 피연산자를 순서대로 담는 배열
vector<char> op; // expressions의 연산자를 순서대로 담는 배열

long long calc(long long a, long long b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
}

void dfs(int n) {
	if (n == 3) {
		vector<long long> temp_num = num;
		vector<char> temp_op = op;

		for (int i = 0; i < priority.size(); i++) { // 연산자 우선순위 대로 진행
			for (int j = 0; j < temp_op.size();) { // 주어진 식의 처음부터 계산 진행
				if (temp_op[j] == priority[i]) {
					long long result = calc(temp_num[j], temp_num[j + 1], temp_op[j]);

					temp_num.erase(temp_num.begin() + j); // 계산된 피연산자 2개를 빼고
					temp_num.erase(temp_num.begin() + j);
					temp_num.insert(temp_num.begin() + j, result); // 피연산자끼리 계산된 결과를 같은 위치에 집어넣는다.
					temp_op.erase(temp_op.begin() + j); // 계산된 연산자도 빼준다.
				}
				else
					j++; // 아직 우선순위가 맞지 않아 계산되지 않은 연산자와 피연산자는 그대로 넣어놓고 다음으로 넘어간다.
			}
		}
		answer = max(answer, abs(temp_num[0]));
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			priority[n] = oper[i];
			dfs(n + 1);
			check[i] = 0;
		}
	}
}

long long solution(string expression) {
	str = expression;

	// 피연산자는 num에, 연산자는 op에 순서대로 나눠서 담아준다.
	while (1) {
		int pos = 0;
		while (pos != str.length() && str[pos] != '+' && str[pos] != '-' && str[pos] != '*') { // 연산자의 위치 찾기
			pos++;
		}

		num.push_back(stoi(str)); // 피연산자 하나를 int로 변환 후 넣어준다.

		if (pos == str.length())
			break;
		op.push_back(str[pos]);
		str = str.substr(pos + 1);
	}

	dfs(0);

	return answer;
}
