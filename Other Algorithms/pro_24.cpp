/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12934 (프로그래머스 Level 1)

임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하는 문제.
n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, n이 양의 정수 x의 제곱이 아니라면 -1을 리턴한다.

<cmath>의 sqrt() 함수를 이용하여 제곱근을 구할 수 있다.

시간복잡도는 O(1)
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long x = sqrt(n);
    
    if (x * x == n) 
        answer = (x + 1) * (x + 1);
    else
        answer = -1;
    
    return answer;
}
