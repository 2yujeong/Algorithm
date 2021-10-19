/*
문제 출처 : https://www.acmicpc.net/problem/2812 (백준 온라인 저지)

N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 문제.

이전에 풀었던 프로그래머스의 '큰 수 구하기' 문제와 동일하다.
(https://github.com/2yujeong/Algorithm/commit/55aafb5f0640de7e961934dfe2b4868d37adec3d)
BOJ의 채점 기준이 프로그래머스보다 더 까다로워서 일부 테스트케이스를 계속 통과하지 못했는데
입력으로 매우 큰 수가 들어와서 자료형 long long으로도 담지 못하는 게 원인이었다.
입출력 시 정수형 대신 string을 이용함으로써 문제를 해결하였다.
프로그래머스의 '큰 수 구하기' 문제를 풀 때는 스택을 이용하였지만 이번에는 deque를 이용하여 풀었다.
자료구조의 앞, 뒤로 삽입과 삭제가 가능하기 때문에 마지막에 reverse로 순서를 뒤집어줄 필요가 없어졌다.

시간복잡도는 deque의 앞, 뒤로 삽입 / 삭제하는 연산의 시간복잡도가 amortized O(1)이므로(할당 공간이 가득 차면 일정 크기의 블록 단위로 확장 필요) 총 O(n)

참고 : vector와 deque의 메모리 확장 비교
자료구조 vector의 경우 할당된 메모리(capacity)를 모두 소진하면 새로운 메모리 공간을 할당받고 기존의 원소값들을 새로운 공간으로 복사하는 reallocation이 발생한다.
이때 기존에 할당받았던 메모리 공간의 vector는 파괴된다.
deque의 경우 일정 크기의 블록 하나만 추가로 할당해주면 되므로 기존 원소들을 복사할 필요가 없다.
하지만 데이터가 저장된 개별 블록들을 가리키는 포인터들은 별도의 vector로 관리되기 때문에 
드문 경우지만 이 vector가 꽉 차면 위에서 언급한 vector의 reallocation이 발생한다.
*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int n, k;
	string number = "";
	cin >> n >> k >> number;

	string result = "";
	int result_size = n - k;

	deque<char> dq;

	for (char n : number) {
		while (!dq.empty() && k > 0 && dq.back() < n) {
			dq.pop_back();
			k--; // k개의 수만 빼면 된다.
		}

		dq.push_back(n);
	}

 	// 98765... 처럼 뒷자리로 갈수록 작아지는 수의 경우 k개 이하의 수를 빼게 될 수 있다.
    	// -> 앞자리의 수가 클수록 큰 수이므로 맨 뒷자리의 수부터 빼낸 수가 총 k개가 될 때까지 다시 빼준다.
	while (dq.size() > result_size) {
		dq.pop_back();
	}

	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;
}
