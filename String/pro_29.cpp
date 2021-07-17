/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/81301 (프로그래머스 Level 1)

숫자의 일부를 다음과 같이 영단어로 바꾼 문자열이 주어진다.
1478 → "one4seveneight"
234567 → "23four5six7"
10203 → "1zerotwozero3"
주어진 문자열이 의미하는 원래 숫자를 리턴하는 문제.

문자열의 문자를 하나씩 탐색하며 숫자면 바로 answer에 넣어주고 영단어면 map을 이용하여 해당하는 숫자로 변환 후 넣어준다.
map은 영단어를 key로, 해당 숫자를 value로 짝지어 저장하며 map.find()를 이용하여 영단어와 매치되는 숫자를 찾는다.

시간복잡도는 map의 find 연산이 O(log m)이므로 문자열의 길이가 n일 때의 총 시간복잡도는 O(nlog m)이다.
이때 map의 크기 m은 10으로 정해져 있으므로 O(nlog 10) = O(n)
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, int> m;
    
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    string temp = "";
    map<string, int>::iterator it;
    
    for (char c : s) {
        if (c >= '0' && c <= '9') 
            answer = answer * 10 + (c - '0');
        else {
            temp += c;
            it = m.find(temp);
            if  (it != m.end()) {
                answer = answer * 10 + it->second;
                temp = "";
            }
        }
    }
    
    return answer;
}
