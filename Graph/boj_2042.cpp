/*
문제 출처 : https://www.acmicpc.net/problem/2042 (백준 온라인 저지)

N개의 수가 초기값으로 주어진다.
그 다음 M + K개의 입력이 a b c 형태로 들어온다.
a가 1인 경우에는 b번째 수를 c로 바꾸고
a가 2인 경우에는 b번째부터 c번째까지의 수들의 구간합을 구해 출력하는 문제.

세그먼트 트리를 이용하여 구간 합을 구하는 문제이다.

[참고] 세그먼트 트리 : 구간합을 저장하기 위한 트리 자료구조로 특정 구간에 대한 합을 미리 계산해서 트리 형태로 저장해놓는다.
n개의 수에 대한 세그먼트 트리는 다음과 같은 형태로 구성된다.
먼저 n개의 수들은 n개의 리프 노드에 그 값들이 그대로 저장된다.
그리고 그 이외의 노드들은 자신의 왼쪽 자식과 오른쪽 자식의 합을 저장한다.
즉 세그먼트 트리의 루트 노드는 n개의 모든 원소들의 합을 저장하고 있게 된다.

세그먼트 트리를 배열을 이용하여 구현할 땐, 부모 노드의 인덱스 i에 대해 왼쪽 자식의 인덱스는 2 * i로, 오른쪽 자식의 인덱스는 2 * i + 1로 설정하는 방식을 사용한다.
그러면 루트 노드는 배열의 1번 위치에, 루트 노드의 자식 노드는 배열의 2, 3번 위치에, 
루트 노드의 왼쪽 자식의 자식 노드는 4, 5번 위치에, 오른쪽 노드의 자식 노드는 6, 7번 위치에 값이 저장되는 형태로 구현된다.
이진 트리의 특성 상 세그먼트 트리를 구현하기 위한 배열의 크기는 2의 제곱수 중 원소의 개수 n보다 크면서 n과 가장 가까운 수를 구한 뒤 그것의 2배로 설정하면 되는데
그 값을 구하기 힘들 때는 대략 n의 4배로 초기화하면 넉넉하게 할당할 수 있다.

문제 풀이는 우선 constructTree 함수를 이용하여 재귀 형식으로 초기 세그먼트 트리를 구성하고
값을 업데이트 할 때는 updateTree 함수를 이용하여 리프 노드부터 상위 노드들을 탐방하며 값을 수정해간다.
특정 구간의 구간합을 찾을 때는 searchTree 함수를 이용하여 
루트 노드부터 시작해 현재 노드가 포함하고 있는 값들의 범위(인덱스)가 찾으려는 구간을 포함하고 있는지 여부를 판단하여 구한다.

시간복잡도는 세그먼트 트리를 이용하지 않고 단순히 입력이 들어올 때마다 더하는 방식은 O(n)이 걸린다.
따라서 m개의 모든 질문에 대해 구간합을 구하려면 시간복잡도는 O(nm)이 된다. 
세그먼트 트리를 이용하면 먼저 초기 트리를 구성하는 과정이 O(n), 값을 업데이트하거나 구간합을 구하는 과정이 각각 O(log n)으로
m개의 모든 질문에 대해 시간복잡도가 O(mlog n)이 된다.
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
	return tree[pos] = constructTree(start, mid, pos * 2) + constructTree(mid + 1, end, pos * 2 + 1);
}

void updateTree(int idx, long long val) {
	idx = v[idx]; // idx번째 값의 세그먼트 트리에서의 인덱스
	tree[idx] = val;
	idx /= 2; // 부모 노드의 인덱스

	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // 트리의 위쪽으로 올라가며 구간합 수정
		idx /= 2;
	}
}

long long searchTree(int start, int end, int left, int right, int pos) {
	if (left > end || right < start) // 찾으려는 범위를 아예 벗어난 경우
		return 0;

	if (left <= start && right >= end) // 구간합을 찾으려는 범위(left ~ right)가 start와 end 사이에 모두 포함된 경우
		return tree[pos];

	int mid = (start + end) / 2;
	return searchTree(start, mid, left, right, pos * 2)  // 왼쪽 자식이 처음 ~ 중간 까지의 합을 가지고 있으므로
		+ searchTree(mid + 1, end, left, right, pos * 2 + 1); // 오른쪽 자식이 중간 + 1 ~ 처음 까지의 합을 가지고 있으므로
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
