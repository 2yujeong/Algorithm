/*
각 행의 평균과 행에서 그 평균에 가장 가까운 값을 출력하는 단순 배열 탐색 문제로 반올림은 0.5를 더한 뒤 int형 변수에 넣어주는 방법으로 처리했다.

시간복잡도는 입력의 크기가 n이라고 할 때 O(n^2)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int map[9];

	for (int i = 0; i < 9; i++) {
		int sum = 0, min = 100, answer = 0;

		for (int j = 0; j < 9; j++) {
			int num;
			cin >> num;

			map[j] = num;
			sum += num;
		}

		int avg = (sum / 9.0) + 0.5; // 반올림
		cout << avg << " ";

		for (int j = 0; j < 9; j++) { // 평균과 가장 가까운 수 찾기
			if (abs(map[j] - avg) < min) { 
				min = abs(map[j] - avg);
				answer = map[j];
			}
			else if (abs(map[j] - avg) == min) { // 평균과 가장 가까운 값이 두 개이면
				if (map[j] > answer) // 둘 중 더 큰 값을 선택
					answer = map[j];
			}
		}

		cout << answer << endl;
	}
	
	return 0;
}
