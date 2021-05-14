/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12977 (프로그래머스 Level 1)

nums 배열에 들어있는 숫자들 중 3개의 숫자를 골라서 서로 더했을 때 소수가 되는 경우의 수를 구하는 문제.

조합과 소수 판별이 필요한 문제로 소수 판별은 에라토스테네스의 체를 이용하였다.
소수 판별 방식은 좀 더 단순하게 while문만 이용하여 판별하는 방식도 있다.
소수인지 판별하려는 수마다 2부터 n^(1/2)까지의 수로 나눠보고 끝까지 나누어떨어지지 않으면 소수로 판별하는 방법으로 이 경우 시간복잡도는 O(n^(1/2))로 n이 커질수록 성능이 떨어진다.
에라토스테네스의 체는 시간복잡도 O(nlog (log n))으로 입력이 클 때 더 유리하다.

시간복잡도는 조합탐색이기 때문에 지수 시간이 걸린다.
*/

#include <vector>

using namespace std;

int sum = 0, cnt = 0;
vector<int> isPrime(3000, 1);

void comb(int value, int level, vector<int>& nums) { // call by reference - vector를 넘길 때 참조변수 사용
	if (level == 3) {
		if (isPrime[sum] == 1) 
            cnt++;

		return;
	}

	for (int i = value; i < nums.size(); i++) {
		sum += nums[i];
		comb(i + 1, level + 1, nums);
		sum -= nums[i];
	}
}

int solution(vector<int> nums) {
	int answer = -1;

	// 에라토스테네스의 체
	for (int i = 2; i * i <= 3000; i++) {
		if (isPrime[i] == 0)
			continue;

		for (int j = i + i; j < 3000; j += i) {
			isPrime[j] = 0;
		}
	}

	// 세 수의 조합을 찾기 위한 재귀함수 사용
	comb(0 , 0, nums);
	answer = cnt;

	return answer;
}
