/*
문제 출처 : https://www.acmicpc.net/problem/2503 (백준 온라인 저지)

민혁이와 영수가 숫자 야구 게임을 한다.
민혁이가 1부터 9까지 서로 다른 세 개의 숫자로 구성된 수를 질문하면 민혁이는 해당 수에 대한 스트라이크의 개수와 볼의 개수를 답해준다.
이러한 질의응답 N개가 입력으로 주어질 때, 정답이 될 수 있는 모든 수의 개수를 구하는 문제.
정답 역시 1부터 9까지 서로 다른 세 개의 숫자로 이루어진다.

123부터 987까지의 모든 수 i에 대해 입력이 들어올 때마다 입력 받은 수 num과 비교하여 스트라이크의 개수와 볼의 개수를 구한다.
i번째 수와 num을 비교하여 각각의 개수를 구한 결과, 두 값 중 하나라도 입력 받은 스트라이크 개수 혹은 볼의 개수와 다르다면 이 i번째 수는 정답이 될 수 없으므로 제외시킨다.
모든 입력에 대해 위와 같은 과정을 거친 후 마지막까지 제외되지 않은 수들의 개수를 출력하면 된다.
주의할 점은 정답은 서로 다른 세 수로 이루어져 있으므로 중복된 수가 포함된 경우는 정답에서 제외시켜야 하며
정답에 0이 포함되는 경우도 없으므로 이 경우도 제외시켜야 한다.
이때 각 자리의 수끼리 비교하기 위해 int형이 아닌 string으로 변환하기 때문에 0과 비교할 때는 int형 0이 아닌 char형 '0'과 비교해야 한다.

시간복잡도는 정답이 될 수 있는 수의 범위가 제한되어 있기 때문에 대략 O(n * 1000 * 3)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> answer(1000, 1);

	for (int i = 0; i < n; i++) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;

		for (int j = 123; j <= 987; j++) {
			if (answer[j]) {
				string ans = to_string(j);

				if (ans[0] == ans[1] || ans[1] == ans[2] || ans[0] == ans[2] ||
					ans[0] == '0' || ans[1] == '0' || ans[2] == '0') { // 주의 - int형 0이 아닌 char형 '0'과 비교해야 한다.
					answer[j] = 0;
					continue;
				}

				int s_cnt = 0, b_cnt = 0;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						if (ans[k] == num[l]) {
							if (k == l) 
								s_cnt++;
							else
								b_cnt++;

							break;
						}
					}
				}

				if (s_cnt != strike || b_cnt != ball)
					answer[j] = 0;
			}
		}
	}

	int cnt = 0;
	for (int j = 123; j <= 987; j++) {
		if (answer[j])
			cnt++;
	}

	cout << cnt;

	return 0;
}
