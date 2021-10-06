/*
문제 출처 : https://www.acmicpc.net/problem/10881 (백준 온라인 저지)

3개의 선물 상자들의 가로, 세로 길이가 주어졌을 때, 선물들을 한꺼번에 포장하는 데 필요한 포장 상자의 최소 크기 (포장 상자의 넓이가 최소가 되는 경우)를 구하는 문제.
선물 상자가 포장 상자의 경계에 접하는 것은 허용되며, 선물 상자는 90도 단위로 회전 가능하다.
포장 상자의 각 변은 선물 상자의 가로 혹은 세로와 평행해야 한다.

입력받은 3개의 상자의 가로, 세로 길이를 size 배열에 pair로 저장한다.
선물 상자는 90도 회전이 가능하므로 일단 입력받은 {가로, 세로}를 먼저 배열에 담고
상자를 90도 회전 시킨 형태인 {세로, 가로}의 경우도 배열에 담음으로써 90도 회전 시켜 담을 수 있는 상자의 모든 형태까지 배열에 담는다.
그러면 입력으로 주어지는 상자의 개수가 3개이므로 배열에 저장된 상자의 형태는 총 6개가 되는데
이 6개 중 3개의 형태를 골라 그 상자들을 담을 포장 상자의 최소 크기를 계산하고, 계산된 크기 중 최소값을 출력하면 된다.
이때 유의할 점은 형태는 다르지만 똑같은 상자 2개를 고르는 경우를 방지해야 한다.
예를 들어 {상자 1의 가로, 상자 1의 세로}-{상자 3의 세로, 상자 3의 가로}-{상자 2의 가로, 상자 2의 세로} 조합은 3개의 상자가 각각 포함되므로 문제가 없지만
{상자 1의 가로, 상자 1의 세로}-{상자 1의 세로, 상자 1의 가로}-{상자 3의 가로, 상자 3의 세로}와 같은 경우는 
원래 입력 받은 형태의 상자 1과 상자 1을 90도 회전시킨 형태, 즉 상자 2 없이 상자 1만 두 번 포함되는 경우이므로 걸러줘야 한다.
3개의 상자를 포장 상자에 담을 때는 2가지 방법을 고려하면 되는데
상자 3개를 쭉 일렬로 담는 경우와 한 줄에는 상자 2개, 다른 한 줄에는 나머지 상자 1개를 담는 방법이 있다.
두 방법에 대해 필요한 포장 상자의 최소 크기를 구하고 그중 더 작은 값을 저장한다.

시간복잡도는 O(n^3)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int box = 2147000000;
		vector<pair<int, int>> size (6);

		for (int i = 0; i < 3; i++) {
			int a, b;
			cin >> a >> b;

			size[i] = { a, b };
			size[i + 3] = { b, a };
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					// 중복된 상자인 경우 방지
					if (k % 3 == j % 3 || j % 3 == i % 3 || i % 3 == k % 3)
						continue;

					// 일렬로 3개를 담는 경우
					int length1 = max({ size[i].first, size[j].first, size[k].first });
					int width1 = size[i].second + size[j].second + size[k].second;

					// 두 줄에 나눠담는 경우(i, j는 한 줄에 담고 k는 다른 줄에)
					int length2 = max(size[i].first, size[j].first) + size[k].first;
					int width2 = max(size[i].second + size[j].second, size[k].second);

					box = min({ box, length1 * width1, length2 * width2 });
				}
			}
		}

		cout << box << endl;
	}

	return 0;
}
