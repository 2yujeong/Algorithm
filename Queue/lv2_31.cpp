/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42583 (프로그래머스 Level 2)

트럭이 최대 bridge_length대 만큼 올라갈 수 있는 다리가 있다. 이 다리는 weight 이하까지의 무게를 견딜 수 있다.
다리를 지나려고 대기 중인 트럭들의 무게가 배열로 주어지고, 이 트럭들은 배열 내 순서에 따라 다리를 지나야 한다고 할 때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는 지 구하는 문제.
이때 트럭 한 대가 다리를 건너는 데 걸리는 시간은 다리의 단위 길이에 비레한다. 즉 bridge_length초 만큼의 시간이 걸린다.

1초가 지날 때마다 트럭이 한 대씩 새로 들어오는 큐를 정의하여 풀었다.
큐의 크기가 점차 커지며 그 크기가 N이 되는 순간, 맨 처음 큐에 들어온 트럭은 N초간 거리 N을 이동한 게 된다.
즉, 큐의 크기가 다리의 길이인 birdge_length가 되는 순간, 맨 처음 들어온 트럭부터 다리를 다 건너서 큐를 빠져나간다.
또한 이 bridge_length는 한꺼번에 다리에 올라올 수 있는 트럭의 최대 개수를 의미하기도 하는데
큐의 크기가 bridge_length가 되는 순간 원소를 하나씩 빼고 다시 넣으므로 다리에 올라온 트럭의 수가 bridge_length를 초과하지 않는 걸 보장할 수 있다.
이때 1초가 지날 때마다 큐의 원소(트럭)들이 거리 1씩 이동했다는 걸 구현하기 위해 1초마다 새로운 트럭을 큐에 넣어줘야 하는데, 다리를 건너는 트럭의 총 무게는 weigth를 넘으면 안 된다.
만약 다음에 들어올 순서인 트럭의 무게까지 합하면 weight를 넘는 경우에는, 이 다음 순서 트럭 대신 무게 0인 트럭을 큐에 넣어준다.
큐에 트럭이 새로 들어옴으로써 1초가 지났다는 걸 알 수 있지만 실제 트럭이 아니므로 전체 무게나 전체 트럭의 수에는 영향을 주지 않는다.
 
시간복잡도는 트럭의 수가 n, 다리의 길이가 m일 때 O(nm)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    int pos = 0, weight_sum = 0;
    
    while (pos != truck_weights.size()) {
        if (q.size() == bridge_length) { 
            weight_sum -= q.front(); // 다리 위의 트럭이 한 대가 빠져나갔으므로 전체 무게에서 빼준다.
            // 만약 weigth 제한 때문에 시간만 맞추기 위해 넣은 원소일 경우 무게 값이 0이므로 전체 무게에 영향을 주지 않는다.
            q.pop();
        }
        
        if (weight_sum + truck_weights[pos] <= weight) {
            q.push(truck_weights[pos]);
            weight_sum += truck_weights[pos];
            pos++;
        }
        else
            q.push(0);
        
        answer++;
    }
    
    return answer += bridge_length;
}
