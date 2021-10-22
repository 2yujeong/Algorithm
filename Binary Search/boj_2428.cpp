/*
문제 출처 : https://www.acmicpc.net/problem/2428 (백준 온라인 저지)

n개의 파일들에 대해 파일 두 개를 한 쌍으로 묶어 각 쌍마다 표절 검사를 실시한다.
이때 크기가 작은 파일이 크기가 큰 파일의 90%보다도 크기가 작을 경우, 해당 쌍은 검사를 하지 않고 넘어가기로 했다.
N개의 파일들의 크기가 주어질 때, 검사 대상이 되는 파일 쌍은 총 몇 쌍인지 구하는 문제.

모든 쌍에 대해 조건을 판별하면 시간초과(O(n^2))로 인해 문제를 풀지 못한다.
오름차순으로 정렬한 뒤 이진 탐색을 이용하여 lower bound를 찾으면 시간복잡도를 통과할 수 있다.
이때 lower bound를 찾는다는 건 자신보다 큰 문서들 중 오름차순으로 몇 번째 문서까지가 자신과 비교 가능한지를 찾는다는 의미이다.
i번부터 lower bound번까지의 문서들이 자신과 비교 가능한 문서들이고 그보다 사이즈가 큰 문서들은 비교할 수 없다.
주의할 점은 정답의 범위가 int형을 넘어가므로 꼭 long long으로 선언해줘야 한다.

시간복잡도는 O(nlog n)

참고 : Lower bound & Upper bound
정렬된 배열에서 찾으려는 값 K에 대해 
Lower bound는 배열에서 K와 같거나 더 큰 수가 처음으로 등장하는 위치를
Upper bound는 배열에서 K보다 큰 수가 처음으로 등장하는 위치를 의미한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> files(n);
	
	for (int i = 0; i < n; i++) {
		cin >> files[i];
	}

	sort(files.begin(), files.end()); // 이진 탐색을 위한 정렬

	long long cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (files[i] < files[i + 1] * 0.9) // Lower bound가 자기자신이므로 비교할 문서가 없다.
			continue;

		// Binary Search
		int left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (files[i] >= files[mid] * 0.9) // mid번째 문서는 비교 대상이 되는 조건을 만족하므로
				left = mid + 1; // mid번째 문서보다 사이즈가 더 큰 문서들을 대상으로 계속해서 lower bound를 찾는다.
			else
				right = mid - 1;
		}

		cnt += right - i; // i + 1번부터 right번까지의 문서들이 i번째 문서와의 비교 대상이 된다.
	}

	cout << cnt;

	return 0;
}
