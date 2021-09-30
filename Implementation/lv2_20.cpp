/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12985 (프로그래머스 Level 2)

토너먼트 형식으로 진행되는 대회에 N명이 참가한다.
만약 1번↔2번 끼리 겨루는 게임에서 2번이 승리했다면 다음 라운드에서 1번을 부여받고, 3번↔4번에서 겨루는 게임에서 3번이 승리했다면 다음 라운드에서 2번을 부여받게 된다.
처음 라운드에서 A번을 가진 참가자가 경쟁자로 생각하는 B번 참가자와 몇 번째 라운드에서 만나는 지를 리턴하는 문제.

시간복잡도는 O(log n)
*/

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 1;

    while (1) {
        if ((a % 2 != 0 && b == a + 1) || (b % 2 != 0 && a == b + 1))
            break;
        
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        
        round++;
    }
    
    return round;
}
