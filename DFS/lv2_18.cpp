/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/72411 (프로그래머스 Level 2)

최소 2명 이상의 손님으로부터 가장 많이 주문된 단품메뉴 조합에 대해 코스요리로 구성하려고 한다.
만약 단품메뉴 n개가 포함된 코스요리를 구성하려고 한다면, n개의 메뉴가 함께 주문된 경우 중 가장 많이 주문된 조합으로 단품메뉴를 구성한다.
각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders, 코스요리를 구성할 단품메뉴의 개수가 담긴 배열 course가 매개변수로 주어질 때, 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 리턴하는 문제.

코스요리를 구성할 단품메뉴의 개수가 n개라면, 한 손님이 주문한 단품메뉴 조합에 대해 n개를 선택하도록 조합탐색을 실행한다.
크기가 n인 조합이 완성되면 map에 저장하고, 모든 손님에 대해 조합탐색을 실행한 뒤 map을 이용하여 해당 조합이 몇 번 등장하는 지를 구한다.
그중에서도 가장 많이 주문된 조합을 선택해야 하기 때문에 map의 요소들을 vector로 옮겨주고 stl sort를 이용하여 오름차순으로 정렬한다.

시간복잡도는 orders 배열의 원소의 길이가 n, course 배열의 원소가 r, orders 배열의 크기가 m, course 배열의 크기가 k일 때 O(km(nCr))
stl sort 때문에 (nCr)log (nCr)이 더 정확하지만 n과 r의 범위가 최대 10까지이기 떄문에 차이가 크진 않을 것이다.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;

void dfs(int value, int level, string& order, string& comb) {
    if (level == comb.length()) {
        m[comb]++;
        
        return;
    }
    
    for (int i = value; i < order.length(); i++) {
        comb[level] = order[i];
        dfs(i + 1, level + 1, order, comb);
    }
}

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second || a.second == b.second && a.first < b.first;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < course.size(); i++) {
        string temp(course[i], ' ');
        
        for (string s : orders) {
            sort(s.begin(), s.end());
            dfs(0, 0, s, temp);
        }

        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), comp);
            
        if (!v.empty() && v[0].second >= 2) {
            for (int i = 0; i < v.size() && v[i].second == v[0].second; i++) {
                answer.push_back(v[i].first);
            }
        }
            
        m.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
