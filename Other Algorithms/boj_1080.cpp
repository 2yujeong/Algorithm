/*
문제 출처 : https://www.acmicpc.net/problem/1080 (백준 온라인 저지)

0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 
행렬 A를 행렬 B로 바꾸는데 필요한 연산 횟수의 최솟값을 구하는 문제.
행렬을 변환하는 연산은 어떤 3×3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다.

행렬의 첫 부분(0행 0열)부터 끝부분(n행 m열)까지 탐색하며 변환 연산이 필요할 때마다 연산을 시행해주는 그리디 문제이다.
행렬 A를 먼저 입력으로 받고 B를 받을 때는 A와 비교하며 check 배열을 채워간다.
check 배열은 행렬 A와 행렬 B의 원소를 비교하여 값이 같은 칸에는 0, 다른 칸에는 1을 저장하는 배열이다.
행렬 A와 B를 같게 만드는 게 목적이므로 check 배열의 원소들을 모두 0으로 만들면 된다.

변환 연산은 한 번 시행됐을 때 원소 값이 바뀌고 한 번 더 시행되면 원래 값으로 돌아온다. 
check 배열의 (0, 0)부터 끝까지의 모든 칸에 대해 3 x 3 변환 연산을 시행해보면
제일 왼쪽 위인 (0, 0)칸의 원소는 연산이 한 번만 적용되기 때문에 무조건 값이 변한다는 것을 알 수 있다.
따라서 check 배열의 (0, 0)부터 탐색하며 값이 1인 칸 (i, j)를 만나면 해당 칸을 연산이 시행될 3 x 3 크기의 부분행렬의 맨 왼쪽 윗칸으로 삼고 
변환 연산을 시행하여 (i + 3, j + 3)까지의 모든 원소들의 값을 바꿔준다.
이 과정을 (n - 3, m - 3)까지 시행했음에도 1인 부분이 남아있다면 그 칸들은 3 x 3 연산을 이용해서는 0으로 바꿀 수 없다는 뜻이므로 -1을 출력한다.

시간복잡도는 변환 연산이 상수 시간에 실행되므로 O(nm)
*/

#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> A(n ,vector<int>(m));
	vector<vector<int>> check(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &A[i][j]); // 숫자를 한 자리씩 받기 위해 scansf 사용
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			scanf("%1d", &temp);

			if (temp != A[i][j])
				check[i][j] = 1;
			else
				check[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (check[i][j] == 1) {
				cnt++;
				for (int x = i; x < i + 3; x++) {
					for (int y = j; y < j + 3; y++) {
						check[x][y] = !check[x][y];
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 1) {
				cout << -1;

				return 0;
			}
		}
	}

	cout << cnt;

	return 0;
}
