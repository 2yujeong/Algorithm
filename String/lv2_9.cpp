/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/60057 (프로그래머스 Level 2)

문자열에서 같은 패턴이 연속해서 나타나는 경우, 연속 구간 전체를 패턴의 반복 횟수와 패턴을 구성하는 문자열로 표현하여 더 짧은 문자열로 줄이려고 한다.
예를 들어 "aabbaccc"의 경우 "2a2ba3c"(문자가 반복되지 않아 한번만 나타난 경우 1은 생략함)와 같이 표현할 수 있다.
이때 압축 단위는 위의 예시처럼 꼭 1일 필요는 없으며 2개 이상의 단위로 문자열을 잘라서 압축할 수도 있다. 
예를 들어 "abcabcdede"와 같은 경우, 문자를 2개 단위로 잘라서 압축하면 "abcabc2de"가 되지만, 3개 단위로 자른다면 "2abcdede"가 되어 3개 단위로 자르면 더 짧게 압축할 수 있다.
압축할 문자열 s가 매개변수로 주어질 때, 위에 설명한 방법으로 1개 이상 단위로 문자열을 잘라 압축하여 표현한 문자열 중 가장 짧은 것의 길이를 리턴하는 문제.

압축 단위를 1부터 s.length() / 2까지 하나씩 늘려가며 각 압축 단위별로 압축된 문자열의 길이를 모두 구하고 비교하는 브루트포스 방식으로 풀었다.

시간복잡도는 for문이 (n / 2), while문이 O(n)이므로 O(n^2)
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 2147000000;
    
    if (s.length() == 1) // 주어진 문자열의 길이가 1인 경우
        return answer = 1;
    
    for (int i = 1; i <= s.length() / 2; i++) { // 압축 단위를 1부터 하나씩 늘려가며 각 압축 단위별로 압축된 문자열의 길이를 구하고 그중 최소 길이를 리턴한다.
        int pos = 0, cnt = 1;
        string str = ""; // 압축된 최종 문자열을 저장할 변수
        
        while (1) {
            if (pos + 2 * i > s.length()) { // 검사할 인덱스가 주어진 문자열의 길이를 넘어갈 경우
                if (cnt > 1) // 앞부터 압축된 문자들이 있으면 압축된 크기를 추가하고
                    str += to_string(cnt);
                str += s.substr(pos); // 나머지 문자열을 모두 넣어준다.
                
                break; // 압축 종료
            }
            
            if (s.substr(pos, i) == s.substr(pos + i, i)) { // 기준 pos로부터 i개의 문자와 그 다음부터 i개의 문자를 비교
                pos += i;
                cnt++; // 비교한 문자들이 같다면 str에 따로 문자열을 추가하지 않고 압축된 크기만 증가
            }
            else { // 비교한 문자들이 같지 않은 경우 앞에서 압축된 내용들을 토대로 str에 문자열 추가
                if (cnt > 1) 
                    str += to_string(cnt); // 2 이상 압축이 되었다면 압축된 크기를 str에 넣고
                str += s.substr(pos, i); // 압축 단위 길이만큼의 문자열을 넣어준다.
                pos += i;
                cnt = 1;
            }
        }
        
        if (str.length() < answer) // 압축 단위별로 압축된 최종 문자열들 중 길이가 가장 짧은 문자열 찾기
            answer = str.length();
    }
    
    return answer;
}
