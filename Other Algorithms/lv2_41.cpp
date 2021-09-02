/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/70129 (프로그래머스 Level 2)

0과 1로 이루어진 어떤 문자열 s에 대한 이진 변환을 다음과 같이 정의한다.
 1. s의 모든 0을 제거
 2. s의 길이를 c라고 하면, s를 "c를 2진법으로 표현한 문자열"로 변환
0과 1로 이루어진 문자열 s에 이진 변환을 가했을 때, 이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 리턴하는 문제.

1번 과정(s의 모든 0을 제거)에서 제거되는 모든 0의 개수를 저장하는 zero 변수와 1의 개수, 즉 0이 모두 제거된 s의 길이를 저장하는 len 변수를 정의한다.
len 변수를 이용하여 2번 과정을 실행하기 위해 while문을 이용하여 len을 이진수로 바꿔주었는데
변환된 이진수를 따로 다른 변수에 저장할 필요 없이 변환 과정에서 등장하는 0의 개수와 1의 개수에 따라 zero 변수와 len 변수를 카운팅해주면 된다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero = 0;
    int len = 0;
    
    for (char c : s) {
        if (c == '1')
            len++;
        else
            zero++;
    }
    
    int i = 1;
    for (; len != 1; i++) {
        int num = len;
        len = 0;
        
        while (num != 0) {
            if (num % 2 == 0)
                zero++;
            else 
                len++;
            
            num /= 2;
        }
    }
    
    answer.push_back(i);
    answer.push_back(zero);
    
    return answer;
}
