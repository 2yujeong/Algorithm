/*
문제 출처 : https://www.acmicpc.net/problem/11505 (백준 온라인 저지)

이전에 풀었던 2042번 '구간 합 구하기' 문제와 유사한 문제로, 세그먼트 트리를 이용하여 구간 곱을 구하면 되는 문제이다. 
2042번과의 차이점은 + 연산 대신 * 연산을 이용하여 트리를 구성하며, 값은 항상 1,000,000,007로 나눈 나머지를 저장해야 한다.
searchTree 함수에서도 합을 구할 때는 찾고자 하는 범위가 현재 노드에 포함되지 않을 때 결괏값에 영향이 없도록 0을 리턴했지만
곱을 구할 때는 1을 리턴해야 결괏값에 영향을 미치지 않는다.

[참고] 세그먼트 트리 - https://github.com/2yujeong/Algorithm/commit/3cafc90811a2c0e632e12cd8078c592edc8cd549

시간복잡도는 세그먼트 트리 구성이 O(n), m개의 질의에 대해 값을 업데이트 하거나 구간 곱을 구하는 과정이 O(mlog n)이 된다.
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
long long tree[4000000];
vector<long long> v;

long long constructTree(long long start, long long end, int pos) {
	if (start == end) { // 리프 노드 값 설정
		tree[pos] = v[start];
		v[start] = pos; // start번째로 입력받은 값의 세그먼트 트리에서의 위치(인덱스) 저장

		return tree[pos];
	}

	int mid = (start + end) / 2;
	return tree[pos] = constructTree(start, mid, pos * 2) 
		* constructTree(mid + 1, end, pos * 2 + 1) % 1000000007;
}

void updateTree(int idx, long long val) {
	idx = v[idx]; // idx번째 값의 세그먼트 트리에서의 인덱스
	tree[idx] = val;
	idx /= 2; // 부모 노드의 인덱스

	while (idx > 0) {
		tree[idx] = tree[idx * 2] * tree[idx * 2 + 1] % 1000000007; // 트리의 위쪽으로 올라가며 구간 곱 수정
		idx /= 2;
	}
}

long long searchTree(int start, int end, int left, int right, int pos) {
	if (left > end || right < start) // 찾으려는 범위를 아예 벗어난 경우
		return 1;

	if (left <= start && right >= end) // 구간합을 찾으려는 범위(left ~ right)가 start와 end 사이에 모두 포함된 경우
		return tree[pos];

	int mid = (start + end) / 2;
	return searchTree(start, mid, left, right, pos * 2)  // 왼쪽 자식이 처음 ~ 중간 까지의 합을 가지고 있으므로
		* searchTree(mid + 1, end, left, right, pos * 2 + 1) % 1000000007; // 오른쪽 자식이 중간 + 1 ~ 처음 까지의 합을 가지고 있으므로
}

int main() {
	cin >> n >> m >> k;

	v.resize(n + 1);
	v[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	constructTree(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		long long  a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			updateTree(b, c);
		else
			cout << searchTree(1, n, b, c, 1) << endl;
	}

	return 0;
}
