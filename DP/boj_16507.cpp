/*
문제 출처 : https://www.acmicpc.net/problem/16507 (백준 온라인 저지)

R x C 크기의 사진이 주어진다. 
R x C개의 각 픽셀들의 밝기 정도와 좌표쌍 (r1, c1), (r2, c2)가 주어질 때
두 좌표를 꼭짓점으로 하는 직사각형의 밝기 평균을 출력하는 문제.

각 위치에서의 픽셀들의 누적합을 저장하는 메모이제이션을 이용하면 
직사각형의 밝기 평균을 물어보는 질의가 여러 개 주어져도 빠른 시간에 답을 출력할 수 있다. 

[DP 테이블 설계]
DP[i][j]는 (1, 1) 위치의 픽셀부터 (i, j) 위치의 픽셀까지의 밝기의 합을 의미한다.
DP 테이블을 채울 때는 방금 입력 받은 값 k에 이전에 계산해놓은 누적합을 이용하여 DP[i][j]를 구하는데
k에 (1, 1)부터 (i - 1, j)까지의 누적합과 (1, 1)부터 (i, j - 1)까지의 누적합을 더하면 
(1, 1)부터 (i, j)까지의 누적합에 (1 ,1)부터 (i - 1, j - 1)까지의 누적합이 중복되므로 DP[i - 1][j - 1]을 한 번 빼줘야 한다.
따라서 DP[i][j]는 k + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1]로 구할 수 있다.
직사각형의 밝기 평균을 구할 때도 DP 테이블을 인덱싱함으로써 쉽게 구할 수 있다. 
먼저 (1, 1)부터 (r2, c2)까지의 누적합 DP[r2][c2]를 구하고 필요 없는 부분은 빼주는데
이 과정에서 중복되어 두 번 빠진 부분은 한 번 더해줌으로써 주어진 직사각형의 밝기의 합을 구할 수 있다.

시간복잡도는 O(rc + q)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int r, c, q;
	cin >> r >> c >> q;

	vector<vector<int>> pixelSum(r + 1, vector<int>(c + 1));

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int k;
			cin >> k;

			pixelSum[i][j] = k + pixelSum[i - 1][j] + pixelSum[i][j - 1] - pixelSum[i - 1][j - 1];
		}
	}

	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int sum = pixelSum[r2][c2] - pixelSum[r1 - 1][c2] - pixelSum[r2][c1 - 1] + pixelSum[r1 - 1][c1 - 1];
		cout << sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) << endl;
	}

	return 0;
}
