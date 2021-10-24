/*
문제 출처 : https://www.acmicpc.net/problem/15961(백준 온라인 저지)

새로 문을 연 회전 초밥 음식점이 불경기로 영업이 어려워서, 다음과 같이 두 가지 행사를 통해서 매상을 올리고자 한다.
 1. n개의 초밥이 올려진 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우, 할인된 정액 가격으로 제공한다. 
 2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다. 
회전 초밥 음식점의 벨트 상태, 메뉴에 있는 초밥의 가짓수, 연속해서 먹는 접시의 개수, 쿠폰 번호가 주어졌을 때 손님이 먹을 수 있는 초밥 가짓수의 최댓값을 구하는 문제.

투포인터를 이용하여 푸는 문제로, 벨트 위에서 k개의 연속된 초밥을 선택할 때 pos1은 맨 앞 순서인 초밥을, pos2는 맨 뒷 순서인 초밥을 가리킨다.
맨 처음에는 0번 ~ k - 1번, 그 다음에는 1번 ~ k번, 2번 ~ k + 1번, ... 의 순서로 초밥 범위를 선택하게 되는데
두 개의 포인터를 1씩 증가시키며 pos1이 가리키는 초밥은 범위에서 빼주고 pos2가 가리키는 초밥은 범위에 더해주는 방식으로 범위를 정하고 cnt 값을 처리해준다.

C++의 경우 입력값이 많아서 ios::sync_with_stdio(false) / cin.tie(NULL)를 추가해주지 않으면 시간 초과가 난다.

시간복잡도는 O(n + k)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> belt(n);
	vector<int> sushi(d + 1);

	for (int i = 0; i < n; i++) {
		cin >> belt[i];
	}

	// 벨트가 회전하므로 뒷 순서의 초밥 -> 앞 순서의 초밥이 정답 범위가 되는 경우를 판별하기 위해 맨 앞 k개의 초밥 종류를 배열의 맨 뒤에 추가 
	for (int i = 0; i < k; i++) { 
		belt.push_back(belt[i]);
	}

	int max_cnt = 0, cnt = 0;
	bool useCoupon = false; // 쿠폰에 해당되는 초밥 종류를 먹었는지 여부

	// pos1부터 pos2까지의 연속된 k개의 초밥을 먹는 모든 경우에 대해 cnt를 구하고 그중 최댓값(max_cnt)을 구한다.
	for (int pos1 = 0, pos2 = 0; pos2 < n + k; pos2++) {
		if (pos2 >= k) { // k개가 넘는 초밥이 연속된 초밥 범위에 포함되는 경우 맨 처음 포함됐던 초밥을 범위에서 제외시킨다.
			if (sushi[belt[pos1]] == 1) // 현재 범위에서 빼려는 초밥(pos1이 가리키는 초밥)이 2개 이상이라면 그 초밥을 빼도 먹는 가짓수에는 변화 X
				cnt--; // pos1 초밥이 범위 내 하나 밖에 없는 초밥이었다면 가짓수가 하나 줄어든다.

			sushi[belt[pos1]]--; // pos1이 가리키는 초밥이 연속된 k개의 초밥 범위에 포함된 횟수가 하나 줄어든다.
			pos1++;
		}

		if (sushi[belt[pos2]] == 0) // pos2가 가리키는 초밥이 초밥 범위에 포함되어 있지 않았던 초밥이라면 가짓수 증가
			cnt++;

		sushi[belt[pos2]]++; // pos2 초밥이 초밥 범위에 포함된 횟수 증가

		if (cnt >= max_cnt) { // cnt의 최댓값이 갱신될 때마다 max_cnt 값 수정
			if (sushi[c] == 0) // 쿠폰을 써서 먹을 수 있는 초밥이 범위에 포함되지 않은 경우
				useCoupon = false;
			else if (cnt > max_cnt) // cnt == max_cnt이면서 useCoupon이 false인 경우가 앞서 있었다면 굳이 true로 바꿀 필요 X
				useCoupon = true;

			max_cnt = cnt;
		}
	}

	if (useCoupon == false)
		max_cnt++; // 쿠폰을 사용하여 추가로 새로운 종류의 초밥을 하나 먹는다.

	cout << max_cnt;

	return 0;
}
