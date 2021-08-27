/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/84325 (프로그래머스 Level 1)

5개의 직업군 별로 직업군 언어 점수를 정리한 문자열 배열 table, 개발자가 사용하는 언어를 담은 문자열 배열 languages, 
언어 선호도를 담은 정수 배열 preference가 매개변수로 주어진다. 
개발자가 사용하는 언어의 언어 선호도 X 해당 언어의 특정 직업군에서의 언어 점수의 총합이 가장 높은 직업군을 리턴하는 문제.
총합이 같은 직업군이 여러 개일 경우, 이름이 사전 순으로 가장 빠른 직업군을 리턴한다.

자료구조 map을 이용하여 개발자가 사용하는 언어별 언어 선호도 값을 매칭하는 방법으로 풀었다.
map.find()로 table의 항목들 중 개발자가 사용하는 언어를 판별해내고
해당 언어와 매칭되는 언어 선호도를 해당 직업군에서의 직업군 언어 점수와 곱하여 총합에 더해주었다.
마지막에 총합이 같은 직업군이 여러 개일 경우, 이름이 사전 순으로 가장 빠른 직업군을 리턴해야 하는데
map은 key 값을 기준으로 오름차순으로 정렬되므로 자료구조를 앞에서부터 탐색할 때 먼저 등장한 key 값이 사전 순으로 더 앞에 위치하는 단어가 된다.
따라서 max 값이 중복된다면 그중 map의 가장 앞에 위치하는 key 값을 리턴하면 된다.

시간복잡도는 table의 크기, table의 원소의 길이, languages의 크기에 의존하지만 이 문제에서는 입력 범위가 모두 크지 않은 상수 범위 내로 한정되어 있다.
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    
    map<string, int> m; // 각 언어별로 언어 선호도 값을 담기 위한 map
    map<string, int> score; // 직군별로 언어 선호도 X 직업군 언어 점수의 총합을 담기 위한 map
    
    for (int i = 0; i < languages.size(); i++) { // 언어-언어 선호도 쌍을 저장
        m[languages[i]] = preference[i];
    }
    
    for (string s : table) {
        int total = 0; // 언어 선호도 x 직업군 언어 점수의 총합
        string job; // 직업군
        
        int ptr = 0;
        for (int i = 6; i >= 1; i--) {
            string temp = "";
            while (ptr < s.size() && s[ptr] != ' ') { // 공백을 기준으로 자른 단어를 temp에 저장
                temp += s[ptr];
                ptr++;
            }
            
            if (i == 6) // 직업군 이름은 job 변수에 저장
                job = temp;
            else if (m.find(temp) != m.end()) // 개발자가 사용하는 언어 중 하나면
                total += m[temp] * i; // 해당 언어의 언어 선호도 X 직업군 언어 점수를 총합에 더해준다.
            
            ptr++;
        }
        
        score[job] = total;
    }
    
    // 총합이 가장 큰 직업군 찾기
    int max = -1;
    for (auto it = score.begin(); it != score.end(); it++) {
        if (it->second > max) { 
            max = it->second;
            answer = it->first;
        }
    }
    
    return answer;
}
