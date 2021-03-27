/*
문제 출처 : https://www.inflearn.com/course/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98# (인프런, 알고리즘 문제풀이 강의)

77번에서 구현한 Union Find와 크루스칼 알고리즘을 활용하여 MST를 찾는 문제.

시간복잡도는 간선을 비용에 따라 오름차선으로 정렬하는 시간에 의존하므로 O(eloge)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int unf[1001];

class info {
public:
	int v1;
	int v2;
	int c;
};

bool comp(info a, info b) { // 간선 가중치 비교 함수
	return a.c < b.c;
}

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
	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) { // 초기화
		unf[i] = i;
	}

	vector<info> list;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		list.push_back({ a, b, c });
	}

	sort(list.begin(), list.end(), comp); // 가중치에 따라 간선 정렬
	
	int cost = list[0].c, cnt = 2; // 첫 번째 간선(비용이 제일 적은 간선) 처리
	unionFind(list[0].v1, list[0].v2);

	for (int i = 1; i < list.size(); i++) {
		if (find(list[i].v1) == find(list[i].v2)) // 사이클이 발생하면
			continue; // 해당 간선은 pass
		else { // 사이클이 발생하지 않으면
			unionFind(list[i].v1, list[i].v2); // 간선의 양 끝 노드들을 Union 연산
			cost += list[i].c; // 해당 간선의 비용을 총 비용에 추가
			cnt++; // 처리된 노드 수 증가
		}

		if (cnt == v)
			break;
	}

	cout << cost;

	return 0;
}
