/*
교차로를 스택으로 구현하여 풀었다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> train; // 입력을 담을 vector

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		train.push_back(num);
	}

	int cnt = 1, i = 0;
	stack<int> s; // 교차로 역할을 하는 stack
	vector<char> answer; // 실행된 작업을 순서대로 저장할 정답 vector
	vector<int> flag(n + 1, 0); // impossible인지 판별하기 위해 각 번호의 기차가 stack에 들어가 있는지 아닌지를 저장하는 vector

	while (cnt <= n) {
		if ((i >= n) || (train[i] != cnt && flag[cnt] == 1)) { // 모든 입력이 stack에 들어간 경우 || 출발 순서인 기차 번호가 도착해야할 기차 번호와 같지 않고 도착해야할 기차가 교차로에 들어가 있는 경우
			if (s.top() == cnt) { // 교차로의 가장 최근 기차가 이번에 도착해야할 기차라면 교차로에서 out
				s.pop();
				answer.push_back('O');
				cnt++;
			}
			else { // 교차로의 안쪽에 있는 경우 도착 순서에 맞게 꺼낼 수 없으므로 impossible
				cout << "impossible";

				return 0;
			}
		}
		else if (train[i] != cnt && flag[cnt] == 0) { // 출발 순서인 기차 번호가 도착해야할 기차 번호와 같지 않고 도착해야할 기차가 교차로에 아직 들어가 있지 않은 경우
			while (train[i] != cnt) { // 도착해야할 기차가 교차로에 들어갈 때까지 앞 순서에 있는 출발 기차들을 모두 push
				s.push(train[i]);
				answer.push_back('P');
				flag[train[i]] = 1;
				i++;
			}
		}
		else { // 출발 순서인 기차 번호가 도착 순서인 기차 번호와 같을 경우
			answer.push_back('P');
			answer.push_back('O');
			cnt++;
			i++;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}

	return 0;
}
