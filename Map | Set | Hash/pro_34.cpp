/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/92334 (프로그래머스 Level 1)

게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 한다.
신고 횟수에는 제한이 없지만 한 유저의 동일한 유저에 대한 신고 횟수는 몇 번을 신고하든 1회로 처리된다.
k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송한다.
이용자의 ID가 담긴 배열 id_list와 신고 정보가 담긴 배열 report가 주어질 때
각 유저별로 처리 결과 메일을 받은 횟수를 리턴하는 문제.

리턴하는 배열은 id_list에 담긴 id 순서를 기준으로 메일 수신 횟수가 담겨야 하기 때문에 
먼저 각 유저별로 id_list에서 몇 번째에 위치하는지 인덱스 값을 저장하는 nameIdx를 map으로 선언하였다.
각 유저들이 신고 당한 횟수와 자신들을 신고한 유저들의 이름은 reporter 배열을 선언하여
reporter[idx]에 저장된 set에 idx번째 유저를 신고한 유저들의 이름을 저장하도록 구현했다.
set을 이용하면 중복을 걸러주기 때문에 한 유저가 동일한 유저를 여러 번 신고하는 경우도 신고 횟수 1번으로 처리할 수 있다.
마지막에는 reporter의 각 인덱스에 저장된 set의 크기를 이용해 idx번째 유저가 신고를 당한 횟수를 구하고
그 횟수가 k번 이상이라면 해당 set에 저장된 신고자들의 메일 수신 횟수를 증가시킨다.
이때 구현에 사용한 map, set은 정렬할 필요가 없으므로 빠른 수행 시간을 위해 hash로 구현된 unordered로 선언하였다.

시간복잡도는 unordered map, set의 삽입, 탐색 연산이 평균적으로 상수 시간에 수행되므로
report 배열의 크기가 m일 때 각 신고 정보를 이용하여 reporter 배열에 insert하는 과정이 O(m)이 된다.
마지막에 reporter 배열을 이용하여 메일 수신을 처리하는 부분의 경우 유저의 수(id_list의 크기)가 n일 때 최대 O(n^2)이 소요된다.
따라서 총 시간복잡도는 O(n^2 + m)
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());
    
    unordered_map<string, int> nameIdx; // 각 유저가 id_list에서 몇 번째 idx에 위치하는지 알기 위함
    
    vector<unordered_set<string>> reporter; // 각 유저별로 해당 유저를 신고한 reporter들의 이름을 중복이 없도록 set으로 저장
    reporter.resize(id_list.size());
    
    for (int i = 0; i < id_list.size(); i++) {
        nameIdx[id_list[i]] = i;
    }
    
    for (string s : report) {
        string name1 = "", name2 = ""; // 신고한 유저와 신고 당한 유저의 이름 저장
        int i = 0;
        while (s[i] != ' ') {
            name1 += s[i++];
        }
        name2 = s.substr(++i);
        
        reporter[nameIdx[name2]].insert(name1); // 신고 당한 유저의 자신을 신고한 신고자 목록에 신고자의 이름을 저장
    }
    
    for (int i = 0; i < reporter.size(); i++) {
        if (reporter[i].size() >= k) { // i번째 유저를 신고한 유저가 k명 이상이라면
            for (auto it = reporter[i].begin(); it != reporter[i].end(); it++) {
                answer[nameIdx[*it]]++; // i번째 유저의 신고자 목록에 존재하는 유저들에게 메일이 간다.
            }
        }
    }
    
    return answer;
}
