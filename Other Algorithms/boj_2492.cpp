/*
문제 출처 : https://www.acmicpc.net/problem/2492 (백준 온라인 저지)

너비 N, 높이 M인 좌표계 형태의 지도에 T개의 금강석의 위치가 입력으로 주어진다.
한 변의 길이가 K인 정사각형 영역 하나에 대해서만 굴착 영역으로 지정하여 금강석을 굴착할 수 있다고 할 때
가장 많은 금강석을 캘 수 있는 경우의 굴착 영역의 좌표와 굴착 가능한 금강석의 개수를 출력하는 문제.

7573번 고기잡이 문제와 유사한 문제이다.
(https://github.com/2yujeong/Algorithm/commit/22069f087b2f9555a8c8cfc466b6559ee1348f37)
완전탐색을 이용하여 가능한 모든 경우에 대해 굴착 가능한 보석의 개수가 가장 많은 경우를 찾아야 한다.
이때 굴착할 영역에 보석이 하나도 없는 경우까지 탐색할 필요는 없으므로
각 보석의 위치를 기준 삼아 굴착 영역의 시작점을 정하고 이 시작점을 기준으로 굴착 영역을 좌우로 옮겨가며 탐색한다.
여기서 굴착 영역의 시작점이란 좌표 i, j를 기준으로 오른쪽으로 k만큼, 아래로 k만큼의 영역을 굴착 영역으로 정한다고 했을 때의 기준점 i, j를 말한다. 

고기잡이 문제와 다른 점은 배열이 아닌 좌표계를 사용하기 때문에 (0, 0)이 왼쪽 위가 아닌 왼쪽 아래라는 점이다.
(0, 0)이 왼쪽 위가 되도록 좌표계를 수평 기준으로 뒤집었다고 생각하고 고기잡이와 똑같은 방식으로 풀어도 답을 구할 수 있지만
문제는 정답이 될 수 있는 굴착 영역이 여러 개인 경우에 어떤 굴착 영역을 정답으로 출력해야 될지가 모호해진다.
출력 설명에서는 '답이 여러 개 있는 경우에는 그 중 하나만 출력하라.'라고만 되어있어서, 여러 답 중 어떤 답을 출력해야 될지가 모호했기 때문에 문제를 푸는 데 오래 걸렸다.
고기잡이에서는 고기의 좌표를 기준점으로 삼았을 때, 기준점의 오른쪽 아래로 그물을 펼쳤다면
이 문제에서는 기준점의 오른쪽 위로 굴착 영역을 전개한다고 생각해야 문제에서 원하는 경우의 정답을 제대로 출력할 수 있다. (좌표계를 수평 기준으로 뒤집어서 푼다고 가정하는 경우)

시간복잡도는 O(k(1 + 2 + 3 + 4 + ... + t))이므로 O(kt^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, t, k;
	cin >> n >> m >> t >> k;
	
	vector<pair<int, int>> jewel;

	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;

		jewel.push_back({ y, x });
	}
	
	sort(jewel.begin(), jewel.end());

	int max = 0;
	int pos_x = k, pos_y = k;

	for (int i = 0; i < t; i++) {
		// 기준점 설정(굴착 영역의 맨 왼쪽 위 좌표)
		int x = jewel[i].second;
		int y = jewel[i].first;

		for (int shift = 0; shift <= k; shift++) { // 굴착 영역을 왼쪽으로 1씩 k번 옮겨가며 탐색
			int cnt = 1;

			if (x - shift < 0 || (x - shift) + k > n) // 굴착 영역이 지도의 너비를 벗어난 경우
				continue;

			// 기준점에 있는 보석보다 아래(좌표상으로는 위)에 있는 보석들에 대해 현재 굴착 영역에 포함되는지 판별
			for (int j = i - 1; j >= 0; j--) { 
				int xx = jewel[j].second;
				int yy = jewel[j].first;

				if (yy < y - k)
					break;

				if ((x - shift) <= xx && (x - shift) + k >= xx)
					cnt++;
			}

			if (cnt > max) {
				pos_x = x - shift;
				if (y - k < 0) // y를 기준으로 굴착 영역을 아래로 전개했을 때 굴착 영역이 지도의 높이를 벗어나는 경우
					pos_y = k;
				else
					pos_y = y;
				max = cnt;
			}
		}
	}

	cout << pos_x << " " << pos_y << endl;
	cout << max;

	return 0;
}
