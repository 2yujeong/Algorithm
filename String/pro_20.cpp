/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12926 (프로그래머스 Level 1)

어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 한다.
문자열 s와 거리 n이 입력으로 주어질 때, s를 n만큼 밀어 만든 시저 암호문을 return하는 문제.

처음엔 문자 c를 n만큼 민 문자(temp = c + n)가 'z'보다 크면 'a'부터 다시 더해지도록 처리했는데, 이런 경우 일부 테스트케이스를 통과하지 못한다.
아스키코드표를 보면 'z'에서 일정 이상 더하면 범위를 벗어나 음수 DEC 값이 나오기 때문에 의도했던 대로 처리할 수 없었던 것이다.
소문자를 처리할 때 'z' 이상으로 밀리는 지 확인하는 방법을 temp > 'z' 대신 n > 'z' - c로 바꿔서 해결했다.

시간복잡도는 O(n), n은 문자열 s의 길이
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char& c : s) {
        if (c == ' ') { // 공백은 밀어도 공백
            answer += " ";
            continue;
        }
        
        char temp = c + n;
        
        if (c >= 'a' && c <= 'z' && n > 'z' - c) // 소문자를 밀어서 'z' 이상이 되는 경우
            temp = 'a' - 1 + (temp - 'z');
        else if (c >= 'A' && c <= 'Z' && n > 'Z' - c) // 대문자를 밀어서 'Z' 이상이 되는 겨우
            temp = 'A' - 1 + (temp - 'Z');
        
        answer += temp;
    }
    
    return answer;
}
