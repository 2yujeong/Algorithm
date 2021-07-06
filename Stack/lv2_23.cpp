/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/76502 (프로그래머스 Level 2)

대괄호, 중괄호, 소괄호로 이루어진 문자열 s가 주어진다. 
이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 리턴하는 문제.

올바른 괄호 판별은 Stack을 이용하였으며 x만큼 회전시킨 각 문자열에 대해 올바른지 모두 판별하는 식으로 문제를 해결했다.
회전시킬 때는 실제로 문자열을 Shift 하지 않고 포인터를 이용하여 구현하였다.

시간복잡도는 O(n^2), n은 문자열 s의 길이
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        stack<char> st;
        int j = i;
        int cnt = 0;
        
        for (; cnt != s.length(); cnt++) {
            if (!st.empty() && (st.top() == '[' && s[j] == ']' 
                || st.top() == '{' && s[j] == '}' || st.top() == '(' && s[j] == ')')) 
                    st.pop();
            else if (s[j] == ']' || s[j] == '}' || s[j] == ')')
                break;
            else
                st.push(s[j]);
            
            if (++j == s.length())
                j = 0;
        }
        
        if (cnt == s.length() && st.empty())
            answer++;
    }
    
    return answer;
}
