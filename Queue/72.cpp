72번 - 공주 구하기 [Queue]
/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

배열을 이용해서 시뮬레이션으로 풀었던 공주 구하기 문제를 큐를 이용하여 더 간단하게 풀 수 있다.

시간복잡도는 1부터 k까지 외치는 과정을 n - 1번 반복해야 마지막 한 명이 남으므로 O(nk)
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int num = 0;
	while (q.size() != 1) { // 큐에 한 명만 남을 때까지 반복
		num++; // 수를 외친다.
		if (num == k) { // k를 외친 왕자는 아예 큐에서 빠지고 수는 다시 1부터 외친다.
			q.pop();
			num = 0;
		}
		else { // k가 아닌 수를 외치면 큐의 맨 뒤로 간다.
			int temp = q.front(); 
			q.pop();
			q.push(temp);
		}
	}

	cout << q.front();

	return 0;
}
