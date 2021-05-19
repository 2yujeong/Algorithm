/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/68935 (프로그래머스 Level 1)

자연수 n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return하는 문제.

시간복잡도는 O(log(3) n)
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    
    while (n >= 3) {
        v.push_back(n % 3);
        n /= 3;
    }
    
    v.push_back(n);
    int num = 1;
    
    for (int i = v.size() - 1; i >= 0; i--) {
        answer += num * v[i];
        num *= 3;
    }
    
    return answer;
}
