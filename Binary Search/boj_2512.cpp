/*
문제 출처 : https://www.acmicpc.net/problem/2512 (백준 온라인 저지)

국가에서는 정해진 총액 이내에서 가능한 한 최대의 예산을 다음과 같은 방법으로 배정한다.
 1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
 2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 정한다.
  - 상한액을 초과하는 예산요청에 대해서는 상한액 만큼만 배정한다. 
  - 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.
여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 각 지방에 배정되는 예산들 중 최댓값을 출력하는 문제.

이진 탐색을 이용하여 가장 적합한 상한액을 구하는 방식으로 풀 수 있다.
각 지방에서 요청하는 예산의 범위는 1 이상 100,000 이하이므로 상한액의 범위 역시 1 이상 100,000 이하가 된다.
따라서 이진 탐색의 초기 시작 지점을 1, 끝 지점을 100,000으로 잡고 
그 중간 지점((시작 지점 + 끝 지점) / 2))의 금액을 상한액으로 정하여 조건에 맞는지 판별하는 방식으로 이진 탐색을 계속 진행한다.

시간복잡도는 지방의 수를 n, 지방에서 요청할 수 있는 예산의 최댓값을 m이라고 할 때 O(n + log m)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLimit(int left, int right, int bound, vector<int>& v) {
	int m = (left + right) / 2;

	if (left > right)
		return m;

	long long sum = 0;
	for (int i : v) {
		if (i > m) // 상한액보다 큰 예산을 요청했다면 상한액 만큼만 배정
			sum += m;
		else // 상한액 이하의 예산을 요청했다면 요청한 금액 그대로 배정
			sum += i;
	}

	if (sum > bound) // 상한액을 m으로 잡고 배정했을 때 총액을 넘어서는 경우
		return findLimit(left, m - 1, bound, v); // 상한액을 너무 크게 잡았으므로 더 적은 상한액에 대해 탐색

	return findLimit(m + 1, right, bound, v); 
	// 현재의 상한액(m)으로도 주어진 조건을 만족하며 배정할 수 있지만, 문제에서 가능한 한 최대로 예산을 배정해야 한다고 했으므로
	// m보다 더 크면서 주어진 조건을 만족하는 값이 있다면 그 값을 찾아 상한액으로 정하기 위해 이진 탐색을 계속 진행한다.
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int m;
	cin >> m;

	if (sum <= m) { // 상한액을 정할 필요 없이 요청된 예산들을 모두 충족할 수 있는 경우
		cout << *max_element(v.begin(), v.end());
		return 0;
	}

	cout << findLimit(1,100000, m, v);

	return 0;
}
