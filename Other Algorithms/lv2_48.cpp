/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12911 (프로그래머스 Level 2)

자연수 n보다 크고 2진수로 변환했을 때 n을 2진수로 변환한 수와 1의 개수가 같은 자연수 중 가장 작은 수를 찾아 리턴하는 문제.

반복문을 이용하여 n보다 큰 자연수들을 2진수로 변환하고 1의 개수가 같은 수를 찾으면 리턴한다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = -1; // n을 2진수로 변환했을 때의 1의 개수
    int one = 0; // n보다 큰 자연수들을 2진수로 변환했을 때의 1의 개수를 저장하는 변수
    
    for (int i = n; one != answer; i++) {
        int num = i;
        while (num != 0) { // 2진수로 변환
            if (num % 2 == 1)
                one++;
            num /= 2;
        }
        
        if (i == n) // n을 2진수로 변환한 경우
            answer = one;
        else if (answer == one) // n보다 큰 수 중 2진수로 변환했을 때 1의 개수가 answer와 같은 경우
            return i;
        
        one = 0;
    }
}
