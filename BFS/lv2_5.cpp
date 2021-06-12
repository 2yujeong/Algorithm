/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/1829 (프로그래머스 Level 2)

m x n 크기의 picture가 주어질 때, picture 내 영역의 개수와 가장 큰 영역의 넓이를 구하는 문제.
여기서 영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.

map(여기선 picture 배열)을 (0, 0)부터 끝까지 탐색하며 탐색되지 않은 새로운 공간이 나오면 큐를 이용하여 BFS를 돌리는 방식으로 구현하였다.
BFS가 한 번 실행되면 하나의 영역이 모두 탐색될 때까지 돌아간다.
탐색되지 않은 새로운 공간이 나와서 BFS가 실행될 때마다 num 변수를 1 증가시켜 총 영역의 개수를 구하고
BFS를 마칠 때마다 탐색된 영역의 크기를 max 변수와 비교하여 가장 큰 영역의 넓이를 저장한다.

시간복잡도는 O(nm)
*/

#include <vector>
#include <queue>

using namespace std;

class area {
public:
    int x, y;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int num = 0;
    int max = 0;
    
    queue<area> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                num++;
                int size = 1;
                int color = picture[i][j];
                
                picture[i][j] = 0;
                q.push({i, j});
                
                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();
                    
                    if (x - 1 >= 0 && picture[x - 1][y] == color) {
                        size++;
                        picture[x - 1][y] = 0;
                        q.push({x - 1, y});
                    }
                    if (x + 1 < m && picture[x + 1][y] == color) {
                        size++;
                        picture[x + 1][y] = 0;
                        q.push({x + 1, y});
                    }
                    if (y - 1 >= 0 && picture[x][y - 1] == color) {
                        size++;
                        picture[x][y - 1] = 0;
                        q.push({x, y - 1});
                    }
                    if (y + 1 < n && picture[x][y + 1] == color) {
                        size++;
                        picture[x][y + 1] = 0;
                        q.push({x, y + 1});
                    }
                } 
                
            if (size > max)
                max = size;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = num;
    answer[1] = max;
    
    return answer;
}
