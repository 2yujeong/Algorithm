/*
문제 출처 : https://www.acmicpc.net/problem/2805 (백준 온라인 저지)

목제 절단기의 높이를 H로 지정하면, 톱날이 땅으로부터 H미터 위로 올라가 한 줄에 연속해있는 나무를 모두 절단해버린다.
즉, 높이가 H보다 큰 나무는 H 위의 부분이 잘리며 낮은 나무는 잘리지 않는다.
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 문제.

이전에 풀었던 예산 문제와 비슷하다.
(https://github.com/2yujeong/Algorithm/blob/master/Binary%20Search/boj_2512.cpp)
이진 탐색을 이용하여 총 M미터 이상의 나무를 얻을 수 있으면서 절단기의 높이가 최대인 경우의 값을 구해야 한다.
절단기에 설정할 수 있는 높이의 범위는 1부터 입력 받은 나무들의 높이 중 가장 큰 값까지이다.
따라서 이진 탐색의 초기 시작 지점을 1, 끝 지점을 입력 받은 나무들의 높이 중 가장 큰 값으로 잡고 
그 중간 지점((시작 지점 + 끝 지점) / 2))의 높이를 절단기의 높이로 설정하여 조건에 맞는지 판별하는 방식으로 이진 탐색을 계속 진행한다.

시간복잡도는 O(n + log m)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

long long findBound(int left, int right, int x) {
	long long mid = (left + right) / 2;

	if (left > right)
		return mid;

	long long sum = 0;
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i] - mid > 0)
			sum += tree[i] - mid;
	}

	if (sum < x)
		return findBound(left, mid - 1, x);

	return findBound(mid + 1, right, x);
}

int main() {
	int n, m;
	cin >> n >> m;

	int max = 0;
	for (int i = 0; i < n; i++) {
		int hight;
		cin >> hight;

		tree.push_back(hight);

		if (hight > max)
			max = hight;
	}

	cout << findBound(1, max, m);

	return 0;
}
