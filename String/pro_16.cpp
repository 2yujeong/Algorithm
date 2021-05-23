/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17682 (프로그래머스 Level 1)

다트 게임의 점수 계산 로직에 따라 총점수를 계산하여 return하는 문제.
- 점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱으로 계산된다.
- 옵션으로 스타상(*) , 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 아차상(#) 당첨 시 해당 점수는 마이너스된다.

temp, pre, flag 변수를 이용하였으며 char to int 형변환은 char형 변수 - '0' 방식으로 해결했다.

시간복잡도는 O(n)
*/

#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int temp = 0, pre = 0, flag = 0; 
    // temp : 현재 기회에서 받은 점수 저장
    // pre : 이전 기회에서 받은 점수 저장('*' 당첨 시 계산을 위한 변수)
    // flag : 정수가 두 번 연속 등장하는 경우(10점)를 판별하기 위한 변수
    
    for (char& s : dartResult) {
        if (s == 'D') 
            temp *= temp;
        else if (s == 'T') 
            temp *= temp * temp;
        
        else if (s == '*') {
            temp *= 2;
            pre *= 2;
        }
        else if (s == '#')
            temp *= (-1);
        
        else if (s != 'S') {
            if (flag == 1) // 정수가 2번 연속 나온 경우 = 10점을 받은 경우
                temp = 10;
            else {
                answer += pre; 
                pre = temp;
                temp = s - '0';
            }
            
            flag = 1;
            continue;
        }
        
        flag = 0;
    }
    
    answer += pre;
    answer += temp;
    
    return answer;
}
