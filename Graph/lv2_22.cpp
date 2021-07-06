/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12978 (프로그래머스 Level 2)

1번 마을에서 N - 1개의 다른 마을들로 배달을 가려고 한다.
마을 간 연결하는 양방향 도로를 통해 각 마을로 이동할 수 있으며 도로를 지날 때 걸리는 시간은 도로별로 다르다.
이동 시간이 K 시간이 넘지 않는 마을로만 배달을 가려고 할 때 배달이 가능한 마을의 개수를 리턴하는 문제.

1 : N 문제로 다익스트라 알고리즘을 이용하여 풀 수 있다.

시간복잡도는 우선순위 큐를 사용하므로 큐에 한 번에 들어갈 수 있는 간선(도로) 정보의 수가 최대 2m이라고 하면 push 연산 시 최악의 경우 O(logm)이 걸린다. 
이 과정을 2m개의 모든 간선에 대해 반복하므로 총 시간복잡도는 O(mlogm) = O(mlogn)이 된다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair<int, int> > > v(N + 1);
    vector<int> dist(N + 1, 500000);
    priority_queue<pair<int, int> > pq;
    
    for (vector<int> temp : road) {
        v[temp[0]].push_back({temp[1], temp[2]});
        v[temp[1]].push_back({temp[0], temp[2]});
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int village = pq.top().second;
        pq.pop();
        
        if (dist[village] < time)
            continue;
        
        for (int i = 0; i < v[village].size(); i++) {
            int road = v[village][i].first;
            int new_path = time + v[village][i].second;
            
            if (dist[road] > new_path) {
                dist[road] = new_path;
                pq.push({new_path, road});
            }
        }
    }
    
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}
