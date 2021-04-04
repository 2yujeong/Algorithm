/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

집들의 좌표와 피자집들의 좌표가 표시된 N x N 도시지도 정보가 주어질 때, 도시의 피자 배달 거리가 최소가 되는 M개의 피자집을 선택하여 그때의 도시의 피자 배달 거리를 출력하는 문제.
각 집의 피자 배달 거리는 해당 집과 도시에 존재하는 피자집들과의 거리 중 최소값을 의미하며 도시의 피자 배달 거리는 각 집들의 피자 배달 거리를 합한 것을 의미한다.
삼성 SW역량평가 기출문제이며 백준에서도 풀어볼 수 있다. (https://www.acmicpc.net/problem/15686)

시간복잡도는 모든 조합의 경우에 대해 탐색하므로 지수 시간이 걸린다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, min_dist = 2147000000;
vector<pair<int, int> > house; // 집들의 좌표값을 담는 vector
vector<pair<int, int> > pizza; // 피자집들의 좌표값을 담는 vector
vector<int> comb; // M개의 피자집들의 조합을 담는 vector

void dfs(int value, int level) {
	if (level == m) { // M개의 피자집들에 대한 하나의 조합이 완성된 경우
		int sum = 0;

		for (int i = 0; i < house.size(); i++) { // 각각의 집들에 대한 피자 배달 거리 구하기
			int tmp_min = 2147000000; 
			
			for (int j = 0; j < m; j++) { // 조합 내 모든 피자집들과의 배달 거리를 계산해보고 그중 최소 거리가 피자 배달 거리가 된다.
				if (tmp_min > (abs(house[i].first - pizza[comb[j]].first) + abs(house[i].second - pizza[comb[j]].second)))
					tmp_min = abs(house[i].first - pizza[comb[j]].first) + abs(house[i].second - pizza[comb[j]].second);
			}
			sum += tmp_min; // 하나의 조합에 대한 각 집들의 피자 배달 거리의 합 저장
		}

		if (sum < min_dist) // 각 집들의 피자 배달 거리의 합이 최소가 될 때의 거리가 정답
			min_dist = sum;

		return;
	}

	// pizza.size()개의 피자집 중 M개의 피자집을 고르는 모든 조합을 구하기 위한 DFS 진행
	for (int i = value; i < pizza.size(); i++) { 
		comb[level] = i;
		dfs(i + 1, level + 1);
	}
}

int main() {
	cin >> n >> m;

	comb.resize(m);

	for (int i = 1; i <= n; i++) { // 좌표값은 1부터 시작
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;

			if (a == 1)
				house.push_back({ i, j });
			else if (a == 2)
				pizza.push_back({ i, j });
		}
	}

	dfs(0, 0);

	cout << min_dist;

	return 0;
}
