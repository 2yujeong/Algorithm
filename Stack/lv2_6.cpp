/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12973 (프로그래머스 Level 2)

직관적으로 생각하면 모든 문자열이 제거되거나 더이상 제거할 수 있는 문자열이 남아있지 않을 때까지 문자열 전체를 탐색하는 방법으로 해결할 수 있지만, 스택을 이용하면 더 좋은 효율성으로 문제를 해결할 수 있다.
문자열의 첫 번째 문자부터 차례로 스택에 넣는 방식으로 진행하되 만약 다음에 들어갈 문자와 스택의 top의 값이 같다면 스택의 top을 pop 해주고 해당 문자는 스택에 넣지 않고 넘어간다.

시간복잡도는 주어진 문자열의 길이인 O(n)
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str) {
    int answer = 0;
    stack<char> s;
    
    for (char c : str) {
        if (!s.empty() && s.top() == c) 
            s.pop();
        else
            s.push(c);
    }
    
    if (s.size() == 0)
        answer = 1;

    return answer;
}
