/*
두 개의 집합이 주어질 때 두 집합의 교집합을 출력하는 문제.
두 집합을 각각 정렬하고 각 집합을 가리키는 포인터를 이용하여 풀면 된다. 1차원 배열을 가리키는 2개의 포인터가 필요하므로 투포인터 알고리즘이라고 부른다.

시간복잡도는 O(min(n, m))
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;

	vector<int> v1(n);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}

	cin >> m;

	vector<int> v2(m);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int p1 = 0, p2 = 0;
	vector<int> v3; // 교집합 원소들을 담을 vector

	while (p1 < n && p2 < m) {
		if (v1[p1] == v2[p2]) { // 교집합 원소를 찾았다면 두 포인터 모두 1씩 증가시킨다.
			v3.push_back(v1[p1]);
			p1++;
			p2++;
		}
		else if (v1[p1] > v2[p2]) // 각 집합은 정렬되어 있고 포인터는 0부터 증가하므로 v1[p1] 값보다 작거나 같은 값은 더 이상 v1에서 나타나지 않는다. -> v2[p2]는 교집합에 포함되지 않는다.
			p2++;
		else // v1[p1]은 교집합에 포함되지 않는다.
			p1++;
	}

	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}

	return 0;
}
