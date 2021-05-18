/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42889 (프로그래머스 Level 1)

전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때 실패율 기준 내림차순으로 스테이지의 번호를 return하는 문제.
- 실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

스테이지 번호와 실패율을 묶어서 저장하기 위해 pair를 이용하였으며 이 pair를 우선순위 큐에 넣음으로써 실패율 기준 내림차순으로, 실패율이 같다면 스테이지 번호 기준 오름차순으로 정렬하였다.
실패율은 나누기 연산을 사용하여 계산하기 때문에 실수형으로 선언해야 한다.

시간복잡도는 우선순위 큐의 삽입이 O(h) = O(log n), 삽입이 n번 일어나므로 O(nlog n) 
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int stage[502];

struct comp {
	bool operator()(pair<int, float> a, pair<int, float> b){
		return (a.second < b.second) || (a.second == b.second && a.first > b.first);
	}
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<int, float>, vector<pair<int, float> >, comp> pq;
    
    for (int s : stages) {
        stage[s]++;
    }
    
    int user = stages.size();
    for (int i = 1; i <= N; i++) {
        if (user != 0) {
            pq.push({ i, (float)stage[i] / user });
            user -= stage[i];
        }
        else
            pq.push({ i, 0.0 });
    }
    
    while (!pq.empty()) {
        answer.push_back(pq.top().first);
        pq.pop();
    }
    
    return answer;
}
