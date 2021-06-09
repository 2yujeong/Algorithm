/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42626# (프로그래머스 Level 2)

모든 음식의 스코빌 지수가 K 이상이 될 때까지 스코빌 지수가 가장 낮은 두 개의 음식을 다음과 같은 방법으로 섞는 걸 반복한다.
- 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 리턴하는 문제.

Min Heap으로 구성된 우선순위 큐를 사용하여 풀었다.

시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int s : scoville) {
        pq.push(s);
    }
    
    while (pq.top() < K) {
        if (pq.size() < 2)
            return -1;
        
        int food1 = pq.top();
        pq.pop();
        int food2 = pq.top();
        pq.pop();
        
        pq.push(food1 + food2 * 2);
        answer++;
    }
    
    return answer;
}
