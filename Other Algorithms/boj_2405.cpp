/*
문제 출처 : https://www.acmicpc.net/problem/2405 (백준 온라인 저지)

n개의 정수 입력에서 a, b, c 세 수를 선택한다고 할 때, 세 수의 중위값과 평균값의 차이가 최대가 되도록 하는 a, b, c를 구하는 문제.

a < b < c라고 할 때 중앙값은 b, 평균값은 (a + b + c) / 3이므로
중위값과 평균값의 차이는 b - (a + b + c) / 3, 즉 (-a + 2b - c) / 3이 된다.
이때 구해야 하는 건 두 값의 '차이'이므로 그 결과는 양수값이 나올 수도 있고 음수값이 나올 수 있다.
따라서 (a - 2b + c) / 3에 대해서도 구해봐야 한다.
출력 시에는 차이값에 X3을 한 수를 출력하라고 했으므로 결국 모든 a - 2b + c와 abs(-a + 2b + c)에 대해 최대값을 구하면 된다.
먼저 모든 a - 2b + c에 대해 최댓값을 구할 때는, a < b < c이므로 c를 주어진 수들 중에서의 최댓값으로 고정시키고
b는 작을수록, a는 클수록 a - 2b + c의 값이 커지므로 b는 오름차순 정렬 시 a보다 한 칸 뒤에 있는 수여야 한다.
모든 abs(-a + 2b + c)에 대해 최대값을 구할 때는 a, c는 작을수록 b는 클수록 abs(-a + 2b + c) 값이 커지므로
a를 주어진 수들 중에서의 최솟값으로 고정시키고 b는 오름차순 정렬 시 c보다 한 칸 앞에 있는 수여야 한다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int answer = 0;

	for (int i = 0; i < n - 2; i++) {
		answer = max(answer, v[i] - v[i + 1] * 2 + v[n - 1]);
	}
	for (int i = 2; i < n; i++) {
		answer = max(answer, abs(-v[0] + v[i - 1] * 2 - v[i]));
	}

	cout << answer;

	return 0;
}
