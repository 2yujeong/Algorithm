/*
문제 출처 : https://www.acmicpc.net/problem/7662 (백준 온라인 저지)

이중 우선순위 큐(dual priority queue)는 전형적인 우선순위 큐처럼 동작하되, 데이터를 삭제할 때의 동작에서 차이가 있다.
데이터 삭제 시 이중 우선순위 큐는 연산 명령에 따라 우선순위가 가장 높은 데이터를 삭제하기도 하고 가장 낮은 데이터를 삭제하기도 한다.
정수만 저장하는 이중 우선순위 큐 Q에 적용될 일련의 연산들이 주어질 때, 모든 연산들을 처리한 후 최종적으로 Q에 저장된 데이터의 최댓값과 최솟값을 출력하는 문제.

정렬된 Map을 이용하면 우선순위 큐와 같은 O(log n)의 삽입 연산으로 Key값에 따라 정렬된 상태로 데이터를 저장할 수 있다.
우선순위 큐는 큐의 top에만 접근 가능하지만 map은 각 원소에 iterator를 이용하여 접근 가능하므로
최솟값을 삭제해야 하는 경우에는 map의 가장 앞에 저장되어 있는 원소를, 최댓값을 삭제해야 하는 경우에는 map의 가장 뒤에 저장되어 있는 원소를 삭제해주면 된다. 
주의할 점은 큐에 들어가는 정수들은 32-bit 정수이므로 long long 자료형을 선언해야 하며
각 테스트 케이스가 끝날 때마다 정답 출력 후 줄바꿈 문자를 끝에 포함해줘야 한다.

시간복잡도는 O(tklog k)
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		map<long long, int> m;

		for (int i = 0; i < k; i++) {
			char op;
			long long n;
			cin >> op >> n;

			if (op == 'I')
				m[n]++;
			else {
				if (m.empty())
					continue;

				map<long long, int>::iterator it;
				if (n == 1) 
					it = --m.end();
				else 
					it = m.begin();

				if (it->second == 1)
					m.erase(it);
				else
					it->second--;
			}
		}

		if (m.empty())
			cout << "EMPTY" << endl;
		else
			cout << m.rbegin()->first << " " << m.begin()->first << endl;
	}
}
