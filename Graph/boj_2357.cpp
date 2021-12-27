/*
문제 출처 : https://www.acmicpc.net/problem/2357 (백준 온라인 저지)

n개의 정수에 대해, a번째부터 b번째까지의 정수들 중의 최솟값과 최댓값을 물어보는 질의가 m개 주어진다.
여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다.
m개의 질의를 입력받은 순서대로 각 a, b에 대한 답을 출력하는 문제.

2042번 '구간 합 구하기' 문제와 유사한 문제로, 세그먼트 트리를 이용하여 각 구간의 최솟값과 최댓값을 구하면 되는 문제이다.
2042번과의 차이점은 + 연산 대신 <algorithm> 라이브러리에 정의되어 있는 min, max 함수를 이용하여 트리를 구성한다.

[참고] 세그먼트 트리 - https://github.com/2yujeong/Algorithm/commit/3cafc90811a2c0e632e12cd8078c592edc8cd549

시간복잡도는 먼저 세그먼트 트리의 구성이 트리의 최대 크기가 4n이므로 O(n), 
m개의 질의에 대해 최솟값과 최댓값을 구하는 과정이 O(mlog n)이 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int minTree[400000];
int maxTree[400000];
vector<int> v;

int constructMinTree(int start, int end, int pos) {
	if (start == end) 
		return minTree[pos] = v[start];

	int mid = (start + end) / 2;
	return minTree[pos] = min(constructMinTree(start, mid, pos * 2), 
		constructMinTree(mid + 1, end, pos * 2 + 1));
}

int constructMaxTree(int start, int end, int pos) {
	if (start == end) 
		return maxTree[pos] = v[start];

	int mid = (start + end) / 2;
	return maxTree[pos] = max(constructMaxTree(start, mid, pos * 2),
		constructMaxTree(mid + 1, end, pos * 2 + 1));
}

int searchMinTree(int start, int end, int left, int right, int pos) {
	if (left > end || right < start)
		return 1000000001;

	if (left <= start && right >= end)
		return minTree[pos];

	int mid = (start + end) / 2;
	return min(searchMinTree(start, mid, left, right, pos * 2), 
		searchMinTree(mid + 1, end, left, right, pos * 2 + 1));
}

int searchMaxTree(int start, int end, int left, int right, int pos) {
	if (left > end || right < start)
		return 0;

	if (left <= start && right >= end)
		return maxTree[pos];

	int mid = (start + end) / 2;
	return max(searchMaxTree(start, mid, left, right, pos * 2),
		searchMaxTree(mid + 1, end, left, right, pos * 2 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	v.resize(n + 1);
	v[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	constructMinTree(1, n, 1);
	constructMaxTree(1, n, 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << searchMinTree(1, n, a, b, 1) << " " << searchMaxTree(1, n, a, b, 1) << "\n";
	}

	return 0;
}
