/*
문제 출처 : https://www.acmicpc.net/problem/11723 (백준 온라인 저지)

비어있는 공집합 S에 대해 다음 연산을 수행하는 프로그램을 작성하는 문제.
 - add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
 - remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
 - check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
 - toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
 - all: S를 {1, 2, ..., 20} 으로 바꾼다.
 - empty: S를 공집합으로 바꾼다. 

bit 변수로 집합 S를 표현하고 비트연산자를 이용하여 풀었다.
비트마스크 기법은 다른 자료구조보다 연산 속도가 빠르고 같은 내용을 더 적은 메모리 사용량으로 표현할 수 있다는 장점이 있기 때문에 이 문제에 적합하다.
입출력이 많고 시간 제한이 타이트한 문제라 C++의 경우 ios::sync_with_stdio(false) / cin.tie(0)을 꼭 선언해야 하며
줄바꿈은 endl 대신 "\n"을 사용해야 통과할 수 있다.

시간복잡도는 O(m)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;

	string s;
	int num, bit = 0;

	for (int i = 0; i < m; i++) {
		cin >> s;

		if (s == "add") {
			cin >> num;
			// bit 변수와 1(0...0001)을 왼쪽으로 x만큼 쉬프트 해준 비트를 OR 연산
			bit |= (1 << num);
		}
		else if (s == "remove") {
			cin >> num;
			bit &= ~(1 << num); // // not 연산으로 num번째 비트만 0으로 만들어 주고 and 연산
		}
		else if (s == "check") {
			cin >> num;

			if (bit & (1 << num))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> num;
			bit ^= (1 << num); // XOR 연산을 이용하여 toggle
		}
		else if (s == "all")
			bit = (1 << 21) - 1;
		// 1을 왼쪽으로 n + 1번 shift 해주면 n번째 비트의 바로 왼쪽 비트(n + 1번째 비트)만 1로 채워지게 되는데 
		// 이 상태에서 1을 빼주면 0번째 비트부터 n번째 비트까지만 1로 채워지게 된다.
		else if (s == "empty")
			bit = 0;
	}

	return 0;
}
