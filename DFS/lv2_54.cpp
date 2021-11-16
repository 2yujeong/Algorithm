/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/87946 (프로그래머스 Level 2)

최대 8개의 각 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있다.
한 유저가 오늘 이 던전들을 최대한 많이 탐험하려 한다.
유저의 현재 피로도 k와 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열이 주어질 때 유저가 탐험할 수 있는 최대 던전 수를 리턴하는 문제.

DFS로 순열을 구하듯이, 유저가 방문할 수 있는 n개의 던전에 대해 가능한 모든 방문 순서를 탐색한다.

시간복잡도는 O(n!)
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> check;
int result = 0;

void dfs(int k, int cnt, vector<vector<int>>& dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            
            if (k >= dungeons[i][0]) // 탐색을 더 진행할 수 있는 경우에만 dfs를 계속 진행한다.
                dfs(k - dungeons[i][1], cnt + 1, dungeons);
            
            check[i] = 0;
        }
    }
    
    result = max(result, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    check.resize(dungeons.size(), 0);
    
    dfs(k, 0, dungeons);
    
    return answer = result;
}
