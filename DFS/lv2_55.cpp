/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/86971 (프로그래머스 Level 2)

n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있다.
이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려 한다. 
두 전력망이 갖게 되는 송전탑의 개수가 최대한 비슷하도록 나눈다고 할 때, 각 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 리턴하는 문제.

n과 wires의 길이의 범위가 크지 않으므로 완전탐색으로 풀 수 있다.
하나의 간선을 지운 뒤 DFS를 이용하여 두 전력망이 가지고 있는 송전탑 개수의 차이를 구하는 과정을 n - 1개의 모든 간선에 대해 실행하고 그중 최솟값을 리턴한다.

시간복잡도는 wires의 길이가 n - 1이므로 O(n^2)
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree; // 트리의 각 노드에 연결된 간선 정보를 저장하는 배열
vector<int> check; // DFS를 저장할 때 노드 방문 여부를 체크하기 위한 배열
int cnt;

void dfs(int n, int disconnected_node) {
    if (n == disconnected_node) // n과 disconnected_node 사이의 간선 정보를 지웠으므로 두 노드는 더이상 연결되어 있지 않기 때문에 더이상 진행 X
        return;
    
    cnt++;
    check[n] = 1;
    
    for (int i = 0; i < tree[n].size(); i++) {
        if (check[tree[n][i]] == 0) 
            dfs(tree[n][i], disconnected_node);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    tree.resize(n + 1);
    check.resize(n + 1);
    
    for (vector<int> wire : wires) { // 트리의 간선 정보 저장
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    for (vector<int> wire : wires) { // 모든 간선 정보에 대해 i번째 간선을 끊었을 때의 결과를 구하고 그중 최솟값을 answer에 저장
        // 변수 초기화
        cnt = 0;
        for (int i = 0; i < n + 1; i++) {
            check[i] = 0;
        }
        
        dfs(wire[0], wire[1]); // DFS로 wire[0]번 송전탑과 연결되어 있는 송전탑들을 탐색
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}
