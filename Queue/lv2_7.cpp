/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42586 (프로그래머스 Level 2)

각 작업이 몇 %까지 진행되었는지 알려주는 작업의 진도가 담긴 progresses 배열과 각 작업의 작업 속도가 담긴 speeds 배열이 주어진다.
이때 progresses 배열은 먼저 배포되어야 하는 작업 순으로 작업의 진도가 담겨있다. 
각 작업들은 진도가 100%가 되면 배포될 수 있으며, 배포 우선순위 상 뒤에 있는 작업들은 작업이 먼저 완료되었더라도 앞 순서의 작업들이 모두 배포될 때까지 기다렸다가 같이 배포될 수 있다.
각 배포시점마다 몇 개의 작업이 배포되는지를 구하는 문제.

작업 완료까지 남은 일수를 배포되어야 하는 순서에 따라 큐에 저장하고, 하루에 배포할 수 있는 작업의 수만큼을 한 번에 pop해주는 방식으로 풀었다.

시간복잡도는 작업의 개수인 O(n)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < speeds.size(); i++) {
        int temp = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)
            temp++;
        
        q.push(temp);
    }
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        int cnt = 1;
        
        while (!q.empty() && q.front() <= temp) {
            q.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
