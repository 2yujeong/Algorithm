/*
문제 출처 : https://www.acmicpc.net/problem/1931 (백준 온라인 저지)

회의실에서는 한 번에 한 개의 회의만 진행될 수 있다.
N개의 각 회의에 대해 시작 시간과 끝나는 시간이 주어질 때, 각 회의가 겹치지 않게 하면서 한 개의 회의실에서 진행될 수 있는 회의의 최대 개수를 구하는 문제.

처음에는 DFS를 이용하여 각 시점마다 회의가 진행되는 경우(이전 회의 종료 시간 <= 현재 회의 시작 시간일 때만)와 진행되지 않는 경우를 모두 진행하며 cnt 값이 가장 큰 경우를 찾았다.
정답은 구할 수 있었지만 시간 초과가 떴고, 이 문제의 키포인트는 DFS가 아닌 종료 시간을 기준으로 한 정렬이었다.
회의의 시작 시간이 빨라도 종료 시간이 늦으면 최대 회의 개수를 만족하기 어려우므로 종료 시간을 기준으로 구현해야 한다.
즉, 빨리 끝나는 회의를 선택할 수록 더 많은 회의가 진행될 수 있다.
따라서 다음과 같은 두 개의 조건을 이용하여 그리디 알고리즘을 구현하면 풀 수 있다.
 1. 회의의 시작 시간이 바로 앞서 진행된 회의의 종료 시간보다 늦거나 같아야 한다.
 2. 회의 종료 시간이 최대한 빨라야 한다.

시간복잡도는 STL Sort를 사용하기 때문에 O(nlog n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back({ end, start });
	}

	sort(v.begin(), v.end()); // 종료 시간을 기준으로 정렬

	int cnt = 1;
	int time = v[0].first; // 진행된 회의의 종료 시간 저장
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= time) { // 회의 시작 시간이 앞서 진행된 회의의 종료 시간보다 늦거나 같다면 회의를 진행할 수 있다.
			cnt++;
			time = v[i].first;
		}
	}

	cout << cnt;

	return 0;
}
