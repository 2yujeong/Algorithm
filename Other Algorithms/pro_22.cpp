/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12932 (프로그래머스 Level 1)

자연수 n을  뒤집어 각 자리 숫자를 원소로 가지는 배열 형태를 리턴하는 문제.

시간복잡도는 O(log(10)n)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while (n > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}
