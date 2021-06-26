/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/1844 (프로그래머스 Level 2)

게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 리턴하는 문제.
벽이 있어서 지나갈 수 없는 자리는 0, 벽이 없는 자리는 1로 표현한다.
상대 팀 진영에 도착할 수 없을 때는 -1을 리턴한다.
BFS를 이용한 간단한 최단거리 찾기 문제이다.

시간복잡도는 O(nm)
*/

#include <vector>
#include <queue>

using namespace std;

class point {
public:
    int x, y, dist;
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    queue<point> q;
    
    q.push({ 0, 0, 1 });
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        if (qx == n - 1 && qy == m - 1)
            return answer = dist;
        
        if (qx - 1 >= 0 && maps[qx - 1][qy] == 1) {
            maps[qx - 1][qy] = 0;
            q.push({ qx - 1, qy, dist + 1 });
        }
        if (qx + 1 < n && maps[qx + 1][qy] == 1) {
			maps[qx + 1][qy] = 0;
			q.push({ qx + 1, qy, dist + 1 });
		}
		if (qy - 1 >= 0 && maps[qx][qy - 1] == 1) {
			maps[qx][qy - 1] = 0;
			q.push({ qx, qy - 1, dist + 1 });
		}
		if (qy + 1 < m && maps[qx][qy + 1] == 1) {
			maps[qx][qy + 1] = 0;
			q.push({ qx, qy + 1, dist + 1 });
		}
    }
    
    return answer = -1;
}
