/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12912 (프로그래머스 Level 1)

두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 return하는 문제.

시간복잡도는 O(|a - b|)
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a == b)
        return a;
    
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    
    return answer;
}
