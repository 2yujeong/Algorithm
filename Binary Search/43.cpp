/*
N개의 곡의 길이를 모두 더한 총 길이를 L이라고 할 때, 1 ~ L을 기준으로 이진 탐색처럼 진행해 가면서 각각의 길이에 대해 주어진 조건이 성립하는지를 판단하는 방식으로 풀어야 한다. 
이진 탐색이 끝나면 성립됐던 길이들 중 가장 짧은 길이를 정답으로 출력한다.
각각의 경우에 대해 되는지 안 되는지를 판단하기 때문에 결정 알고리즘이라고도 불린다.

시간복잡도는 O(nlogn)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int n, m;
	cin >> n >> m;

	int sum = 0, max = -1;
	for (int i = 0; i < n; i++) {
		int length;
		cin >> length;

		v.push_back(length);
		sum += length;
		if (max < length)
			max = length;
	}

	int f = 1, e = sum, min = 10000;
	while (f <= e) {
		int mid = (f + e) / 2;

		int cnt = 1, sum = 0, flag = 1; // cnt : 사용된 DVD 개수
		for (int i = 0; i < n; i++) {
			if (sum + v[i] > mid) { // 곡들의 길이의 합이 기준 시간(mid)을 넘기는 경우
				cnt++; // 이번 곡부터 다음 DVD에 저장한다.
				sum = v[i]; 
			}
			else // 이번 DVD에 곡을 더 합칠 수 있는 경우
				sum += v[i]; // 이번 곡까지 더한다.

			if (cnt > m || mid < max) { // 사용된 DVD의 개수가 주어진 m을 초과하거나 기준 시간이 제일 긴 곡의 길이보다 짧은 경우
				flag = -1;
				break;
			}
		}

		if (flag == -1)
			f = mid + 1;
		else {
			if (min > mid)
				min = mid; // 가능한 비디오의 길이들 중 최소 길이를 저장
			e = mid - 1;
		}
	}

	cout << min;

	return 0;
}
