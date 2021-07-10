/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42578 (프로그래머스 Level 2)

스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장한다.
스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 리턴하는 문제.

만약 상의 3개가 있고 하의 2개가 있다면 상하의 조합을 고르는 경우의 수는 3 * 2 = 6이 된다.
하지만 문제에서는 꼭 상의, 하의 종류별로 하나씩 입어야 한다는 조건이 없으므로 상의를 입고 하의를 입지 않거나 하의를 입고 상의를 입지 않는 경우도 존재한다.
따라서 (상의 선택지 3개 + 상의를 선택하지 않는 경우 1) * (하의 선택지 2개 + 하의를 선택하지 않는 경우 1) = 4 * 3 = 12와 같이 계산해야 한다.
이때 이 12개의 조합에는 상의, 하의 둘 다 입지 않는 경우까지 포함되어 있다.
문제에서 스파이는 하루에 최소 한 개의 의상을 입어야 한다는 조건이 있으므로 이 아무것도 입지 않는 하나의 경우를 마지막에 빼줘야 한다.

시간복잡도는 O(n), n은 clothes 배열의 크기
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string ,int> m;
    
    for (vector<string> v : clothes) {
        m[v[1]]++; // 의상의 종류별로 몇 개의 옷이 있는지 저장
    }
    
    for (unordered_map<string, int>:: iterator it = m.begin(); it != m.end(); it++) {
        answer *= (it->second + 1);
    }
        
    return answer - 1; // 하루에 최소 한 개의 의상은 입어야 하는데 아무런 의상도 입지 않은 경우가 포함되어 있으므로 그 경우 하나를 빼준다.
}
