/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12933 (프로그래머스 Level 1)

입력 정수 n의 각 자릿수에 대해 큰 수부터 내림차순으로 정렬한 새로운 정수를 리턴하는 문제.

to_string(), stoll() 같은 string 관련 함수들을 활용하면 쉽게 풀 수 있다.
참고로 <algorithm>의 sort() 함수는 vector뿐만 아니라 string에도 적용할 수 있다.

시간복잡도는 입력 정수 n이 m자리 수라고 할 때 O(mlog m)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
	string s = to_string(n);
	sort(s.begin(), s.end(), greater<char&>()); // string 내림차순 정렬
  answer = stoll(s); // string -> long long 변환
    
	return answer; 
}
