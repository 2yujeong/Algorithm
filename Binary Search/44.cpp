/*
이전에 풀었던 뮤직비디오 문제와 비슷하게 이진 탐색 방식으로 풀었다. 
우선 입력받은 좌표를 오름차순으로 정렬하고 while문을 통해 이진탐색 방식으로 진행한다. 
각각의 경우에 대해 배치했을 때 가장 가까운 두 말의 거리를 near 변수에 저장하고, C마리의 말을 모두 마구간에 배치하는 데에 성공한 경우들 중 가장 먼 near 값을 max_dist 변수에 저장 후 출력한다.

시간복잡도는 STL 정렬 알고리즘이 O(nlogn), 각각의 케이스에 대해 가장 가까운 두 말의 거리가 최대가 되는 경우를 찾는 과정이 O(nlogn)이므로 O(nlogn)이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int f = 1, e = v.back(), max_dist = -1;
	while (f <= e) {
		int mid = (f + e) / 2;

		int pos = v[0], horse = 1, near = 1000000001;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] >= pos + mid) { // 이번 마구간(v[i])이 이전에 말이 들어간 마구간(pos)과 기준 거리(mid) 이상 떨어져 있는 경우
				if (v[i] - pos < near) // 가장 가까운 거리인지 확인
					near = v[i] - pos;

				pos = v[i];
				horse++; // 마구간에 들어간 말의 마릿수 증가
			}

			if (horse >= c) // 말이 모두 들어갔다면 for문 종료
				break;
		}

		if (horse >= c) {
			if (max_dist < near) // 기준 거리가 mid일 때 두 말 간의 가장 가까운 거리가 다른 기준 거리들에 비해 최대인지 확인
				max_dist = near;
			f = near + 1;
		}
		else
			e = mid - 1;
	}

	cout << max_dist;

	return 0;
}
