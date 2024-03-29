/*
문제 출처 : https://www.acmicpc.net/problem/9663 (백준 온라인 저지)

N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓으려고 한다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 문제.
퀸이 서로 공격할 수 없게 놓으려면 각 퀸을 기준으로 가로, 세로, 대각선 방향에 다른 퀸이 놓여있으면 안 된다.

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제로 대표적인 백트래킹 문제이다.
N x N 체스판을 구현하기 위해 2차원 배열을 사용할 필요 없이 각 행 별 퀸이 놓여진 열의 위치를 저장하는 1차원 배열만 사용하여 풀 수 있다.
배열의 i번째 인덱스의 값 j는 체스판의 i행 j열에 퀸이 놓였다는 것을 의미한다.
체스판의 0행 0열부터 DFS를 진행하여 퀸이 놓일 자리를 찾으며 가지치기를 하는 조건은 다음과 같다.
1. 현재 퀸을 놓으려는 자리가 앞서 이미 놓인 퀸들 중 하나와 가로 or 세로 방향으로 겹치는 위치인 경우
 -> 배열에 열의 위치가 같은 원소가 하나라도 있는지 판별함으로써 조건을 구현할 수 있다.
2. 현재 퀸을 놓으려는 자리가 앞서 이미 놓인 퀸들 중 하나와 대각선 방향으로 겹치는 위치인 경우
 -> 행 번호 차이와 열 번호 차이가 같은 원소가 하나라도 있는지 판별함으로써 조건을 구현할 수 있다.
예를 들어 1행 3열에 퀸을 놓으려는데 v[0] = 2인 경우, |0 - 1| == |2 - 3|이므로 서로 같은 대각선상에 위치하기 때문에 1행 3열에는 퀸을 놓을 수 없다.
이런 경우에는 DFS를 더이상 진행하지 않고 백트래킹 한다.

시간복잡도는 DFS만 사용했을 경우 O(n!)이지만 백트래킹을 적용하여 가지치기 해주면 실제로는 훨씬 더 빠른 시간에 수행된다.

[참고] 백트래킹 : DFS에 가지치기(Pruning)를 적용하여 알고리즘의 효율을 더 높여주는 기법으로 
DFS 진행 중 해가 될 가능성이 없는 자식을 만나면 더이상 DFS를 진행하지 않고 이전 노드로 되돌아가는(Backtracking) 방법을 의미한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void dfs(int level, int n, vector<int>& v) {
	if (level == n) { // n개의 퀸을 모두 놓은 경우
		answer++;

		return;
	}

	for (int i = 0; i < n; i++) { // level 행의 0번째 열부터 퀸이 놓일 수 있는 위치인지 판단
		int flag = 0;
		for (int j = 0; j < level; j++) {
			if (v[j] == i) { // 윗행에 이미 놓인 퀸들 중 하나와 열이 겹치는 경우
				flag = 1;
				break;
			}

			if (abs(j - level) == abs(v[j] - i)) { // 윗행에 이미 놓인 퀸들 중 하나와 대각선상 겹치는 경우
				flag = 1;
				break;
			}
		}

		if (flag == 1) // level행 i열에는 퀸을 놓을 수 없으므로 백트래킹 
			continue;
		
		// 퀸을 놓을 수 있는 경우에는 퀸을 놓고 계속해서 dfs 진행
		v[level] = i;
		dfs(level + 1, n, v);
	}
}

int main() {
	int n;
	cin >> n;

	// v[i] = j : i번째 행에 놓인 퀸의 열의 위치가 j -> (i, j)에 퀸이 위치
	vector<int> v(n);

	dfs(0, n, v);

	cout << answer;

	return 0;
}
