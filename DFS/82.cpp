/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

N개의 자연수 중 R개를 뽑아 일렬로 나열한 모든 결과와 그 개수를 출력하는 문제.
부모 노드는 N개의 자식 노드를 갖는다. 나열한 수에 중복이 있으면 안 되므로 check 배열을 이용하여 부모 노드와 값이 같은 자식 노드는 dfs를 진행하지 않고 넘어간다. 결과 값은 레벨 0부터 마지막 레벨(N - 1)까지 내려오면서 거쳤던 노드의 값을 result 배열에 넣고 (마지막 레벨 + 1)에 도달하면 result 배열 값을 출력한다. 

시간복잡도는 순열이므로 O(nPr) = O(n!)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, r, cnt = 0;
vector<int> v;
vector<int> check;
vector<int> result;

void dfs(int n) {
	if (n == r) {
		for (int i = 0; i < r; i++) {
			cout << result[i] << " ";
		}

		cout << "\n";
		cnt++;

		return;
	}

	for (int i = 0; i <= r; i++) {
		if (check[i] == 0) { // 이제껏 거쳐온 경로에 자신과 중복되는 노드 값이 있는지 체크
			check[i] = 1; // 다음 레벨로 내려갔을 때 중복되는 값에 대해서는 dfs를 더 진행하지 않도록 1로 초기화
			result[n] = v[i]; // 현재 거치고 있는 경로의 노드 값을 결과 배열에 저장
			dfs(n + 1); // r개의 노드를 거친 경로가 될 때까지 dfs 진행
			check[i] = 0; // 상위 노드로 backtracking 해서 다른 경로로 다시 dfs를 진행해야 하므로 0으로 초기화 
		}
	}
}

int main() {
	cin >> n >> r;

	v.resize(n);
	check.resize(n);
	result.resize(r);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dfs(0);

	cout << cnt;

	return 0;
}
