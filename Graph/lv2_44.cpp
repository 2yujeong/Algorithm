/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/49993 (프로그래머스 Level 2)

스킬들을 배우기 위한 선행 스킬 순서와 스킬트리들을 담은 배열이 주어질 때, 가능한 스킬트리의 개수를 리턴하는 문제.
주어진 순서에 포함되지 않는 스킬들은 순서에 상관없이 배울 수 있다.

스킬 간의 선후관계를 따지는 위상정렬 구현 문제이다.
그래프를 이용하여 각 스킬을 정점으로, 선후관계를 간선으로 표현하며 진입차수를 이용하여 해결한다.
선행 스킬 순서에서 스킬들은 중복해서 주어지지 않으므로 모든 스킬들의 진입차수는 1을 넘지 않는다.

시간복잡도는 스킬의 총 개수가 알파벳 개수로 한정되어 있으므로 진입차수 배열과 인접그래프를 채우는 과정이 O(1),
하나의 스킬트리가 가능한 스킬트리인지 판별하는 과정이 O(n)이지만 이 역시 n의 범위가 알파벳 개수로 한정되어 있으므로 O(1)이다.
따라서 총 시간복잡도는 스킬트리 배열의 크기에 의존하므로 O(m)
*/

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<int> indegree(27, 0); // 각 정점별 진입차수(자신보다 선행되어야 하는 스킬의 개수) 저장
    vector<vector<int> > v(27); // 스킬 순서 상 자신보다 뒤에 있는 스킬들을 저장하는 인접그래프
    
    for (int i = 0; i < skill.size() - 1; i++) {
        indegree[skill[i + 1] - 'A']++; 
        v[skill[i] - 'A'].push_back(skill[i + 1] - 'A');
    }
    
    for (string s : skill_trees) {
        vector<int> temp = indegree;
        
        for (int i = 0; i < s.length(); i++) {
            if (temp[s[i] - 'A'] != 0) //  선행되어야 하는 스킬이 아직 선행되지 않은 상태이므로 불가능한 스킬 트리
                break;
            
            // s[i]보다 선행되어야 하는 스킬이 없거나 이미 선행되었다면 s[i]를 배울 수 있다.
            for (int j = 0; j < v[s[i] - 'A'].size(); j++) {
                temp[v[s[i] - 'A'][j]]--; // 스킬 순서 상 자신보다 뒤에 있던 스킬들의 진입차수를 하나 줄여준다.
            }
            
            if (i == s.length() - 1)
                answer++;
        }
    }
    
    return answer;
}
