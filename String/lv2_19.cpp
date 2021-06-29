/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/60058 (프로그래머스 Level 2)

'(' 와 ')' 로만 이루어진 문자열이 있을 경우, '(' 의 개수와 ')' 의 개수가 같다면 이를 균형잡힌 괄호 문자열이라고 부른다.
그리고 여기에 '('와 ')'의 괄호의 짝도 모두 맞을 경우에는 이를 올바른 괄호 문자열이라고 부른다.
균형잡힌 괄호 문자열이 입력으로 주어지면 주어진 과정에 따라 올바른 괄호 문자열로 변환한 결과를 리턴하는 문제.

시간복잡도는 O(n)
*/

#include <string>
#include <vector>

using namespace std;

string bracket(string& str) {
    if (str.empty()) // Step 1
        return str;
    
    string u = "", v = "";
    int balanced = 0, flag = 0, i = 0;
    
    // Step 2
    for (; i < str.length(); i++) { // make u
        if (str[i] == '(') 
            balanced++;
        else {
            balanced--;
            if (balanced < 0)
                flag = 1;
        }
        u += str[i];
        
        if (balanced == 0)
            break;
    }
    
    if (i < str.length() - 1) // make v
        v = str.substr(i + 1);
    
    if (flag == 0)  // Step 3 - u가 올바른 괄호 문자열인 경우
        return u + bracket(v);
    else { // Step 4 - u가 올바른 괄호 문자열이 아닌 경우
        string result = "(" + bracket(v) + ")"; // Step 4-1 ~ 4-3
        
        for (int i = 1; i < u.length() - 1; i++) { // Step 4-4
            if (u[i] == '(')
                result += ")";
            else
                result += "(";
        }
        
        return result; // Step 4-5
    }
}

string solution(string p) {
    string answer = "";
    answer = bracket(p);
    
    return answer;
}
