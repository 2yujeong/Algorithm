/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12951 (프로그래머스 Level 2)

JadenCase란 모든 단어의 첫 문자만 대문자이고 그 외의 알파벳들은 모두 소문자인 문자열을 의미한다. 
문자열 s가 주어졌을 때 s를 JadenCase로 바꾼 문자열을 리턴하는 문제.

C++ string 라이브러리에 정의되어 있는 tolower() 함수와 toupper() 함수를 이용하면 쉽게 풀 수 있다.

시간복잡도는 O(n)
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer += toupper(s[0]);
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == ' ') 
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
    }
    
    return answer;
}
