/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

D일 안에 와서 강연을 하면 M만큼의 강연료를 받을 수 있는 강연 요청이 N개 들어왔을 때, 가장 많은 돈을 벌 수 있는 강연 스케줄을 짜야 하는 문제.

참고 : 
비교 함수를 작성할 때는 비교 연산만 적용하고 값의 변경은 일어나지 않도록 const를 붙여주는 게 바람직하다. 
비교 함수를 연산자 오버로딩을 이용하여 클래스 내 멤버 함수로 선언해주는 경우에는 매개변수 앞 뿐만 아니라 함수명 뒤에도 const를 붙여줌으로써 클래스 내 멤버 변수들을 변경할 수 없도록 막아주는 게 좋다.

시간복잡도는 d만큼 반복문이 돌고 STL sort가 nlogn이므로 O(d + nlogn))
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int> > v;

	for (int i = 0; i < n; i++) {
		int m, d;
		cin >> m >> d;

		v.push_back(make_pair(m, d));
	}

	sort(v.begin(), v.end(), comp); // 날짜가 많이 남은 순으로 내림차순 정렬

	priority_queue<int> pq;
	int day = v[0].second, income = 0, idx = 0;
	for (int i = day; i > 0; i--) { // 가장 많이 남은 날짜부터 스케줄링
		while (idx < v.size() && v[idx].second == day) { // 해당 날짜에도 할 수 있는 강의(강의 기한이 해당 날짜와 같거나 더 여유로운 강의)들을 모두 우선순위 큐에 삽입
			pq.push(v[idx].first);
			idx++;
		}

		if (!pq.empty()) {
			income += pq.top(); // 할 수 있는 강의들 중 가장 수입이 높은 강의를 그 날 참여할 강의로 선택
			pq.pop();
		}
	}

	cout << income;

	return 0;
}
