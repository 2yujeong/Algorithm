/*
문제 출처 : https://www.acmicpc.net/problem/1874 (백준 온라인 저지)

1부터 n까지의 수를 스택에 차례대로 하나씩 넣는다.
수를 넣는 도중에 스택의 top을 하나씩 pop할 수 있는데, 이렇게 pop한 수들을 먼저 pop된 순서대로 나열하여 하나의 수열을 만들 수 있다.
입력으로 임의의 수열이 주어졌을 때, 위와 같은 방법으로 스택을 이용해 그 수열을 만들 수 있는지 없는지를 판단하고
만들 수 없다면 "NO"를, 만들 수 있다면 push와 pop이 어떤 순서대로 실행되는지를 출력하는 문제.
push는 "+"를, pop은 "-"를 출력한다.

스택을 이용하여 입력에 따라 push, pop 연산을 직접 실행해 감으로써 풀 수 있다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<char> answer;
	stack<int> s;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// 1부터 오름차순으로 스택에 push할 수 있으므로 top이 num보다 작을 경우 num까지 push 해준다.
		while (cnt <= num) { 
			s.push(cnt++);
			answer.push_back('+');
		}

		if (num == s.top()) { // top이 num과 같아질 경우 pop해서 수열에 추가해준다.
			answer.push_back('-');
			s.pop();
		}
		else { // top이 num과 같지 않을 경우
			// num과 같은 수는 이미 스택의 top보다도 아래에 존재한다는 뜻이 된다. 
			// 그렇다면 스택 특성상 top보다 먼저 pop해서 수열에 추가할 수가 없으므로 중단한다.
			cout << "NO";
			answer.clear();
			break;
		}
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}
