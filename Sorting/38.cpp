/*
Inversion Sequence : 1부터 n까지의 수를 한 번씩만 사용하여 이루어진 수열이 있을 때, 1부터 차례로 각각의 수 앞에 놓여있는 자신보다 큰 수들의 개수를 수열로 표현한 것

1부터 n까지의 수열의 Inversion Sequence가 주어졌을 때 원래의 수열을 출력하는 문제. 큰 수(n)부터 처리하는 게 핵심인 문제이므로 스택을 사용하였다. 
위치를 찾아 삽입하기 위해 다른 수들을 한 칸씩 옮기는 삽입정렬 응용 문제이다.

시간복잡도는 O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;

	stack<int> s;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		s.push(num);
	}

	for (int i = n - 1; i >= 0; i--) { // 큰 수부터 처리 -> 자신(i)보다 큰 숫자들은 이미 모두 결과(v)에 들어있는 상태
		int temp = s.top();
		s.pop();

		for (int j = i; j < i + temp; j++) { // 자신의 원래 위치 i에서 자신 보다 큰 수의 개수(temp) 만큼 뒤로 간 위치에 저장
			v[j] = v[j + 1]; // 그 앞의 수들(자신 보다 큰 수들)은 한 칸씩 앞으로 옮긴다.
		}
		v[i + temp] = i + 1;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}
