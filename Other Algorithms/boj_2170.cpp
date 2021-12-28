/*
문제 출처 : https://www.acmicpc.net/problem/2170 (백준 온라인 저지)

매우 큰 도화지에 일직선으로 x점부터 y점까지 선을 그으려고 한다. 
선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있으며, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별하지 않는다.
입력으로 선을 그을 때 선택한 두 점의 위치들을 담은 배열이 주어질 때, 그려진 선들의 총 길이를 구하는 문제.

선들이 겹치는 경우와 겹치지 않는 경우를 나눠서 생각해야 한다. 
우선 입력으로 주어진 선들의 시작점과 끝점에 대해, 시작점을 기준으로 정렬한다.
자신보다 시작점이 더 앞인 선에 대해, 선의 끝점이 자신의 시작점과 같거나 더 뒤에 있다면 해당 선은 자신과 겹치는 선이 된다.
이때 주의할 점은 앞의 선과 겹친다고 해서 무조건 내 끝점이 겹치는 선의 끝점이 되는 건 아니라는 것이다.
앞 선의 끝점과 내 끝점을 비교하여 더 큰 값을 겹치는 값의 끝점으로 설정해줘야 한다.
앞 선과 겹치지 않는 경우에는 새로운 선이 그려진다는 뜻이므로, 앞서 구해놨던 앞 선의 시작점과 끝점을 기준으로 선의 길이를 구해 sum에 추가해준다.
그리고는 이제 자신이 새로운 선이 되므로 자신의 시작점과 끝점을 새로운 선의 시작점과 끝점으로 설정해준다.

시간복잡도는 STL sort()를 이용한 정렬로 인해 O(nlog n)이 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> points(n);

	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

	sort(points.begin(), points.end()); // 각 선들의 시작점을 기준으로 정렬

	int sum = 0;
	int lineStart = points[0].first, lineEnd = points[0].second;
	for (int i = 1; i < n; i++) {
		if (points[i].first <= lineEnd) { // 시작점이 앞에 위치한 선들과 겹치는 경우
			lineEnd = max(lineEnd, points[i].second); // 값이 더 큰 끝점을 겹치는 선의 끝점으로 설정
		}
		else { // 겹치지 않는 경우
			sum += lineEnd - lineStart;
			lineStart = points[i].first;
			lineEnd = points[i].second;
		}
	}
	sum += lineEnd - lineStart;

	cout << sum;

	return 0;
}
