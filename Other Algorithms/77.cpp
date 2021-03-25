/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

Union & Find 알고리즘을 이용하여 Disjoint Set(Union Find) 자료구조를 구현하는 문제.
Disjoint Set 구현은 트리를 이용하였으며 트리는 1차원 배열을 이용하여 구현하였다. 각각의 인덱스가 노드 번호이며 자신의 부모 노드의 번호(혹은 루트 노드의 번호 - Path Compression)를 배열 값으로 가지고 있다. 
Find 연산으로 자신의 루트 노드의 번호를 재귀적으로 탐색하며 Union 연산으로 루트 노드 번호가 다른 두 집합의 루트 노드 번호를 맞춰준다.

참고 : union by rank 최적화
-> 이러한 구현은 트리가 일렬로 쭉 이어진 연결리스트 형태가 된다면 최악의 성능을 낸다. 
이러한 상황을 방지하기 위해 rank 배열에 각 노드별로 자신이 속한 트리의 높이를 저장하고 Union 시 높이가 더 낮은 트리가 더 높은 트리에 merge되게 구현하면 높이가 1 이상은 늘어나지 않으므로(높이가 1 늘어나는 경우는 두 트리의 높이가 같은 경우) 성능을 조금 더 향상시킬 수 있다.
weighted union 휴리스틱(합집합 시 원소가 더 많은 집합에 원소가 더 적은 집합을 붙이는 전략)이라고도 하며 이번 문제풀이에는 필요 없어서 구현하지 않았다.

시간복잡도는 Find 연산이 O(logn)이고 Union 연산은 Find 연산의 시간복잡도에 의존하므로 총 시간복잡도는 O(logn)이다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int unf[1001];

int find(int n) { // Find 연산
	if (n == unf[n]) // 자신이 루트 노드라면 
		return n; // 자신의 노드 번호 리턴

	// 루트 노드가 아니라면 재귀를 이용하여 루트 노드 탐색
	return unf[n] = find(unf[n]); // Path Compression - 편향된 트리를 피하기 위해 경로 압축
}

void unionFind(int a, int b) { // Union 연산
	// 먼저 find 연산으로 각 노드가 속한 트리의 루트 노드 번호 비교
	int r1 = find(a);
	int r2 = find(b);

	if (r1 != r2) // 루트 노드 번호가 다르다면
		unf[r1] = r2; // Union 진행
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // 초기화
		unf[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		unionFind(a, b);
	}

	int a, b;
	cin >> a >> b;

	if (find(a) == find(b))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
