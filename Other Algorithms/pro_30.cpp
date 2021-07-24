/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/77884 (프로그래머스 Level 1)

left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고 홀수인 수는 뺀 결과를 리턴하는 문제.
보통 어떤 수 n의 약수는 1과 자기자신(n)을 무조건 포함하는데, n = 1인 경우 약수가 1 하나뿐이라는 것을 유의하지 않으면 테스트케이스에서 실패할 수 있다.

시간복잡도는 left가 n, right가 m일 때 O(m^2 - n^2)
*/

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++) {
        int cnt = 1; // 모든 수의 약수인 1 포함
        for (int j = 2; j <= i; j++) {
            if (i % j == 0)
                cnt++;
        }
        
        if (cnt % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}
