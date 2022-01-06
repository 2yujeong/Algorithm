/*
문제 출처 : https://www.acmicpc.net/problem/17521 (백준 온라인 저지)

1일부터 n일까지 n일 동안의 바이트 코인의 등락 정보가 주어진다.
1일에 초기 현금 W원을 가지고 시작하여 마지막 n일 날 보유하고 있는 모든 코인을 매도한다고 할 때, 
보유하게 될 최종 현금의 최댓값을 구하는 문제.

코인 등락 그래프에서 연속되는 구간에서의 최저점과 최고점을 구하는 그리디 문제이다.
그래프가 연속해서 하락하다가 i일에 오른다고 하면, i - 1일 날 코인을 매수한다.
그래프가 연속해서 증가하다가 i일에 내려간다고 하면, i - 1일 날 코인을 매도한다.
즉, 연속된 구간에서의 최저점에서 코인을 매수하고 그 다음 연속된 구간에서의 최고점에서 코인을 매도하면 최대 이익을 얻을 수 있다.
이때 문제를 풀면서 유의할 점은 초기 현금은 많지 않더라도 최종 현금은 매우 많아질 수 있으므로 long long 형을 써줘야 한다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	long long w;
	cin >> n >> w;

	long long preCoinPrice, coinPrice, totalCoin = 0;
	cin >> preCoinPrice;

	int variance = -1; // 그래프의 증감 여부를 판단하기 위한 변수 (-1 : 하락중인 구간 / 1 : 상승중인 구간)
	for (int i = 1; i < n; i++) {
		cin >> coinPrice;

		if (variance == -1 && coinPrice > preCoinPrice) { // 이전날이 연속된 구간에서의 최저점이었던 경우 전날을 기준으로 매수
			totalCoin += w / preCoinPrice;
			w %= preCoinPrice;
			variance = 1;
		}
		else if (variance == 1 && coinPrice < preCoinPrice) { // 이전날이 연속된 구간에서의 최고점이었던 경우 전날을 기준으로 매도
			w += preCoinPrice * totalCoin;
			totalCoin = 0;
			variance = -1;
		}

		preCoinPrice = coinPrice;
	}

	w += coinPrice * totalCoin;
	cout << w;

	return 0;
}
