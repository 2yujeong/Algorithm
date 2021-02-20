/*
재귀 함수로 구현한 Binary Search Algorithm

시간복잡도는 STL 정렬 알고리즘이 O(nlogn), Binary Search가 O(logn)이므로 O(nlogn)이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binarySearch(int f, int e, int key) {
	if (f > e)
		return -1;

	int m = (f + e) / 2;
	if (v[m] == key)
		return m;
	else if (v[m] > key)
		return binarySearch(f, m - 1, key);
	else
		return binarySearch(m + 1, e, key);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int idx = binarySearch(0, v.size() - 1, m);
	cout << idx + 1;

	return 0;
}
