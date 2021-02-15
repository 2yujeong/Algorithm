/*
LRU 알고리즘을 따르는 캐시 메모리를 구현하는 문제. 캐시 사이즈와 작업 번호들이 입력되면 Cache Miss와 Cache Hit가 모두 처리된 후의 캐시 메모리의 상태를 차례로 출력해야 한다.
차례로 앞(왼쪽)의 원소들과 비교하여 삽입될 위치를 찾고 그 위치에 삽입하기 위해 원소들을 한 칸씩 뒤로 옮기는 삽입정렬 응용 문제이다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int s, n;
	cin >> s >> n;

	vector<int> cache(s);

	for (int i = 0; i < n; i++) {
		int work;
		cin >> work;

		int hit = -1;
		for (int j = s - 1; j >= 0; j--) { // Hit인지 Miss인지 판별
			if (cache[j] == work) {
				hit = j;
				break;
			}
		}

		if (hit == -1) { // Cache Miss
			for (int j = s - 1; j > 0; j--) { // 맨 뒤에서부터 작업 번호들이 차례로 한 칸씩 뒤로 밀린다.
				cache[j] = cache[j - 1];
			}

			cache[0] = work;
		}
		else if (hit != 0) { // Cache Hit
			for (int j = hit; j > 0; j--) { // Hit가 발생한 위치부터 뒤로 한 칸씩 밀린다.
				cache[j] = cache[j - 1];
			}

			cache[0] = work;
		}
	}

	for (int i = 0; i < s; i++) {
		cout << cache[i] << " ";
	}

	return 0;
}
