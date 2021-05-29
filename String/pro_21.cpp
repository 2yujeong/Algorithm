/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12925 (프로그래머스 Level 1)

주어진 문자열 s를 숫자로 변환한 결과를 리턴하는 문제.

시간복잡도는 O(n), n은 문자열 s의 길이
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int num = 1;
    
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '-') {
            answer *= -1;
            break;
        }
        else if (s[i] == '+')
            break;
        
        answer += num * (s[i] - '0');
        num *= 10;
    }
    
    return answer;
}
