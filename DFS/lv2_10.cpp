/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/43165 (프로그래머스 Level 2) 

numbers 배열의 숫자들을 적절히 더하거나 빼서 타겟넘버를 만들 수 있는 경우의 수를 구하는 문제.

시간복잡도는 O(2^n)
*/

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int value, int level, vector<int>& numbers, int target) {
    if (level == numbers.size()) {
        if (value == target)
            answer++;
        
        return;
    }
    
    dfs(value + numbers[level], level + 1, numbers, target);
    dfs(value - numbers[level], level + 1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
        
    return answer;
}
