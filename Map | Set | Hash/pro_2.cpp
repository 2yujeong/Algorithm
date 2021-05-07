/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42576 (프로그래머스 Level 1)

참가자 명단이 담긴 participant 배열과 완주한 선수들의 이름이 담긴 completion 배열이 입력으로 주어질 때, 완주하지 못한 1명의 선수의 이름을 return하는 문제.

첫 번째 for문에서 연관 컨테이너 자료구조를 이용하여 participant 배열의 이름들을 Key로, Value는 1로 초기화 한 원소를 삽입한다.
두 번째 for문에서 completion 배열에 속하는 이름이 Key 값이면 그 Value를 다시 1 감소시킨다.
마지막에는 iterator를 이용하여 Value가 0이 아닌 원소를 찾고 그 원소의 이름을 return한다.

참고 : STL map은 Red-Black Tree를 이용한 자료구조로 원소 삽입 시 Key 값에 따라 정렬이 일어난다. -> 탐색 시 시간복잡도 O(log n)
hash_map은 Hash Table 방식으로 원소 삽입 시 정렬이 되지 않으며 hash 값에 따라 버킷에 저장된다. -> 탐색 시 시간복잡도 O(1)
unordered_map은 hash_map과 기능이 동일하며 차이점은 hash_map은 비표준, unordered_map은 표준이므로 unordered_map 사용을 권장한다.
이 문제는 삽입 시 정렬이 필요 없으므로 unordered_map을 사용하면 조금 더 나은 성능을 낼 수 있다.

시간복잡도는 O(n) 
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> um;
    
    for (string name : participant) {
        um[name]++;
    }
    
    for (string name : completion) {
        um[name]--;
    }
    
    map<string, int>::iterator it;
    
    for (it = um.begin(); it != um.end(); it++) {
        if (it->second != 0)
            answer = it->first;
    }
    
    return answer;
}
