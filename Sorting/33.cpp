/*
입력된 N개의 정수(수학성적) 중 3등의 성적을 출력하는 문제. algorithm의 정렬 알고리즘 sort()를 사용하여 쉽게 풀었다.

참고 : stl의 정렬 알고리즘은 정확히 말하자면 quick sort가 아닌 intro sort 알고리즘을 사용한다.
intro sort는 quick sort를 변형한 알고리즘으로 최악의 경우에도 O(nlogn)을 유지하며 비교 기반의 정렬 알고리즘 중에서 가장 빠르다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;

		v.push_back(score);
	}

	sort(v.begin(), v.end(), greater<int>());

	int cnt = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] != v[i + 1]) {
			cnt++;

			if (cnt == 3) {
				cout << v[i + 1];
				break;
			}
		}
	}

	return 0;
}