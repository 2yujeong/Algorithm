/*
문제 출처 : https://www.acmicpc.net/problem/1300 (백준 온라인 저지)

A[i][j] = i×j인 N x N 배열 A를 일차원 배열 B에 넣는다.
N x N 길이의 B의 원소들을 오름차순 정렬 했을 때의 B[k]를 구하는 문제.

입력의 범위가 크기 때문에 1부터 K번째까지의 원소들을 일일이 구해보는 건 시간초과가 난다.
B의 K번째 원소의 값이 mid라고 가정한 뒤 mid가 B에서 몇 번째 원소인지를 구하고
mid가 k번째 원소가 아니라면 탐색 범위를 바꿔가며 진행하는 이진 탐색을 이용하여 풀 수 있다.
mid가 몇 번째 원소인지 구하는 과정은 다음과 같다. 
1번 행부터 N번 행까지, i번째 행에 대해 mid / i를 해줌으로써 i번째 행에서 몇 개의 원소가 mid보다 같거니 작은지 알 수 있다.
i번째 행의 원소들은 모두 i의 배수이기 때문이다.
만약 mid / i가 n보다 크다면, A는 N x N 행렬이라 N번째 열까지밖에 없으므로 mid / i가 아닌 n이 i번째 행에서 mid보다 작은 원소의 개수가 된다.

시간복잡도는 log(nlog n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

long n, k;
long result = 0;

long binarySearch(long f, long e) {
	if (f > e)
		return result;

	long mid = (f + e) / 2; // k번째 원소가 mid라고 가정

	long idx = 0;
	for (int i = 1; i <= n && i <= mid; i++) {
		idx += min(n, mid / i);
	}

	if (idx < k)
		return binarySearch(mid + 1, e);

	result = mid;
	return binarySearch(f, mid - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << binarySearch((long) 1, n * n);

	return 0;
}
