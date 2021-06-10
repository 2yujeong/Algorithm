/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42888 (프로그래머스 Level 2)

오픈채팅방에서 누군가 채팅방에 들어오고 나가거나, 닉네임을 변경함에 따라 방을 개설한 사람이 최종적으로 보게되는 메시지를 리턴하는 문제.

처음에는 각 문자들에 대해 ' '를 만날 때까지 for문을 도는 방식으로 문자열에서 ID와 닉네임을 구분했는데,
아래 코드처럼 istringstream와 getline을 이용하여 문자열을 split하는 코드를 따로 구현하였더니 코드도 훨씬 깔끔해지고 실행 시간도 빨라졌다.
istringstream은 <sstream> 헤더파일 선언을 통해 사용할 수 있는 stream class다.
구현 방식의 경우 처음에는 record vector의 뒤에서부터 진행하는 방식으로 한 번의 for문만 이용하여 구현하였다. 
ID가 map에 이미 존재한다면 map을 갱신하지 않고, 존재하지 않으면 map에 새로 등록하는 방식으로 구현하였는데, 이럴 경우 answer vector를 채우기도 복잡해지며 메모리 초과가 일어난다.
map에 닉네임을 저장하는 과정과 answer vector를 채우는 과정을 구분해줘야 한다.

시간복잡도는 map이 레드블랙 트리로 구현되어 있으므로 삽입, 탐색이 log n에 일어난다. 
for문이 record의 사이즈(n)만큼 진행되므로 총 시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    // 각 유저들의 최종 닉네임을 map에 저장
    for (int i = 0; i < record.size(); i++) {
        vector<string> word;
        
        // 문자열 split
        istringstream ss(record[i]);
        string s;
        while (getline(ss, s, ' ')) {
            word.push_back(s);
        }   

        if (word[0] == "Change" || word[0] == "Enter") 
            m[word[1]] = word[2];
    }
    
    // 각 유저들의 닉네임이 저장된 map을 이용하여 answer vector 채우기
    for (int i = 0 ; i < record.size(); i++) {
        vector<string> word;
        
        istringstream ss(record[i]);
        string s;
        while (getline(ss, s, ' ')) {
            word.push_back(s);
        }     
        
        if (word[0] == "Enter")
            answer.push_back(m.find(word[1])->second + "님이 들어왔습니다.");
        else if (word[0] == "Leave")
            answer.push_back(m.find(word[1])->second + "님이 나갔습니다.");
    }
    
    return answer;
}
