/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17684 (프로그래머스 Level 2)

문자열을 압축하기 위한 LZW 압축을 구현하는 문제.
LZW 압축 과정은 다음과 같다.
 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
 3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
 5. 단계 2로 돌아간다.
압축 알고리즘은 영문 대문자만 처리하며, 사전은 색인 번호 1부터 26까지 26개의 알파벳 대문자로 초기화되어 있다.

문제에 주어진 LZW 압축 과정을 의사코드 삼아 그대로 구현하면 되는 문제열 처리 문제이다.
사전은 map을 이용하여 구현하였으며 pos 변수로 앞에서부터 순차적으로 현재 처리될 순서인 문자열을 가리킨다.
pos부터 시작하는 입력의 부분 문자열들 중 사전에 존재하는 문자열과 가장 길게 매치되는 문자열(w)을 찾을 때는
substr()을 사용하여 pos 위치의 문자부터 i개의 연속된 문자로 이루어진 부분 문자열에 대해 사전에 존재하는지 판별하되 조건을 만족하는 i 중 가장 큰 i를 찾도록 구현하였다.
예를 들어 주어진 입력이 APPLE이고 pos = 0인 경우
APPLE -> APPL -> APP -> AP -> A 순으로 문자열이 사전에 존재하는지 판별한다.

시간복잡도는 압축 효율이 좋지 않은 문자열이 입력으로 주어졌을 경우 최대 O(n^2)이 걸린다. 
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m; // 사전 역할을 해줄 map
    for (int i = 1; i < 27; i++) { // A부터 Z까지 사전에 저장
        string s(1, i - 1 + 'A');
        m[s] = i;
    }
    
    int pos = 0; // 앞에서부터 순차적으로 처리될 순서인 문자열을 가리키는 포인터
    while (pos <= msg.length() - 1) {
        // pos부터 시작하는 입력의 부분 문자열들 중 사전에 존재하는 문자열 중 하나와 가장 길게 매치되는 부분 문자열 찾기
        for (int i = msg.length() - pos; i > 0; i--) { 
            if (m.find(msg.substr(pos, i)) != m.end()) { // pos 위치에서부터 i개의 문자들로 이루어진 부분 문자열이 사전에 존재하는 경우(w를 찾은 경우)
                answer.push_back(m[msg.substr(pos, i)]); // w에 해당하는 사전의 색인 번호 push
                
                if (i + pos != msg.length()) // 처리되지 않은 다음 글자(c)가 남아있다면
                    m[msg.substr(pos, i + 1)] = m.size() + 1; // w + c를 사전에 등록
                pos = pos + i; // 부분 문자열 시작 포지션을 c로 옮김
                
                break;
            }
        }
    }
    
    return answer;
}
