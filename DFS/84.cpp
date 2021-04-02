/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

1일부터 N일까지의 일자별 상담 소요 시간(T일)과 상담 완료 금액(P원)이 주어졌을 때 N + 1일까지 얻을 수 있는 최대 수익을 구하는 문제.
삼성 SW역량평가 기출문제이며 백준에서도 풀어볼 수 있다. (https://www.acmicpc.net/problem/14501)
입력의 크기가 작아서 완전탐색으로 풀었지만 DP를 이용하여 풀 수도 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, result = 0;
vector<pair<int, int> > v(1); // first : 상담 완료까지 걸리는 날수(t), second : 상담 완료시 받는 금액(p)

void dfs(int day, int money) {
	if (day == n + 1) {
		if (result < money)
			result = money;

		return;
	}

	if (day + v[day].first <= n + 1) // day 날짜에 상담을 하는 경우
		dfs(day + v[day].first, money + v[day].second);
	if (day + 1 <= n + 1) // 상담을 하지 않고 다음날로 넘어가는 경우
		dfs(day + 1, money);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;

		v.push_back(make_pair(t, p));
	}

	dfs(1, 0);

	cout << result;

	return 0;
}
