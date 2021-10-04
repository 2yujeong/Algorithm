/*
문제 출처 : https://www.acmicpc.net/problem/1107 (백준 온라인 저지)

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. 
+를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 
M개의 고장난 숫자 버튼의 정보가 주어질 때 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 문제.

0번부터 900000까지의 모든 채널에 대해 숫자 버튼만으로 이동할 수 있는 채널인지 확인한 후,
이동할 수 있는 채널이라면 100번에서부터 해당 채널을 거쳐 N번 채널로 가기까지의 버튼을 누른 횟수를 구한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	if (m == 10) { // 숫자 버튼이 모두 고장난 경우
		cout << abs(n - 100); // 100번을 기준으로 +, - 버튼으로만 움직여야 한다.
		return 0;
	}

	vector<int> button(10);

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		button[a] = 1;
	}

	int min_val = 2147000000;
	for (int i = 0; i < 900000; i++) {
		int channel = i, cnt = 0;

		// 채널의 1의 자리 숫자부터 차례로 고장나지 않은 버튼인지 반복문을 이용하여 확인해 간다.
		while (button[channel % 10] == 0) {
			cnt++;
			channel /= 10; 

			if (channel == 0) { // 모든 자리의 수가 고장나지 않은 버튼이라면 해당 채널은 숫자 버튼만으로 이동할 수 있는 채널이다.
				// 100번에서부터 숫자 버튼으로 i번 채널을 거쳐 +, - 버튼으로 n번 채널로 이동하기까지의 버튼을 누른 횟수 계산
				min_val = min(min_val, cnt + abs(i - n)); 
				break;
			}
		}
	}

	if (min_val > abs(n - 100)) // 숫자 버튼을 이용하여 이동하는 것 보다 100번에서 +, - 버튼만을 이용하여 이동하는 게 더 빠른 경우
		cout << abs(n - 100);
	else
		cout << min_val;

	return 0;
}
