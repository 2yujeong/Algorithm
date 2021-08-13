/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17679 (프로그래머스 Level 2)

같은 모양의 카카오프렌즈 블록이 2×2 형태로 4개가 붙어있을 경우 사라지면서 점수를 얻는 게임을 구현하는 문제.
블록이 지워진 후에 위에 있는 블록이 아래로 떨어져 빈 공간을 채우게 된다.
만약 빈 공간을 채운 후에 다시 2×2 형태로 같은 모양의 블록이 모이면 다시 지워지고 떨어지고를 반복하게 된다.

(m - 1) x (n - 1) 개의 각 블럭에 대해 자신과 자신의 오른쪽, 아래, 오른쪽 아래 대각선에 있는 블럭이 모두 같은 블럭이라면 블럭이 터지도록 처리해줬다.
똑같은 블럭이 2번 이상 터지는 것(중복 카운트 되는 것)을 막고 블럭이 터진 빈 공간을 체크해놓기 위해 map 배열을 선언하였다.

시간복잡도는 2x2 형태로 똑같은 모양 4개가 붙어있는 블럭을 탐색하는 과정이 O(nm),
빈 공간을 채우는 과정이 O(nm)이 걸린다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<int> > map(m, vector<int> (n, 1)); // 하나의 판에서 지워진 모든 블럭들을 0으로 표시, 지워지지 않았다면 1로 표시
    int cnt = answer;
    
    while (1) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char c = board[i][j];
                
                // (m - 1) x (n - 1) 개의 모든 블럭에 대해
                // 자신과 자신의 오른쪽, 아래, 오른쪽 아래 대각선에 있는 블럭이 모두 같은 블럭인지 확인
                if (c != 'X' && board[i][j + 1] == c && 
                    board[i + 1][j] == c && board[i + 1][j + 1] == c) {
                    // 앞에서 이미 4개가 붙어서 지워진 블럭이 포함될 수 있으므로 map을 이용
                    // 이미 지워졌던 블럭이라면 map 값이 0이므로 카운트되지 않는다.
                    answer += map[i][j]; 
                    answer += map[i][j + 1];
                    answer += map[i + 1][j];
                    answer += map[i + 1][j + 1];
                    
                    // 현재 판에서 지워졌다는 의미에서 0으로 설정
                    map[i][j] = 0;
                    map[i][j + 1] = 0;
                    map[i + 1][j] = 0;
                    map[i + 1][j + 1] = 0;
                }
            }
        }
        
        if (cnt == answer) // 모든 블럭을 탐색하고 터트리는 과정을 수행했음에도 터진 블럭이 하나도 없다면 게임 종료
            break;
        
        cnt = answer;
        
        // 블럭이 터진 자리를 그 위에 있던 블럭들이 채우도록 판의 상태를 수정해주는 해주는 과정
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i > 0; i--) {
                int temp = i;
                if (map[temp][j] == 0) { // 원래 있던 블럭이 터져서 빈 공간이 된 경우
                    while (temp > 0 && map[temp][j] == 0) { // 터진 블록 바로 위에 남아있는 다른 블럭 탐색
                        board[temp][j] = 'X'; // 터져있는 공간은 빈 공간이라는 뜻으로 'X'로 설정
                        temp--;
                    }
                    
                    if (map[temp][j] == 1) { // 터진 자리 위에 남아있던 블럭이 있다면 
                        board[i][j] = board[temp][j]; // 그 블럭이 빈 공간을 채워준다.
                        map[i][j] = 1; // 빈 공간이 다시 채워졌으므로 1
                        map[temp][j] = 0; // 원래 남아있던 블럭이 빈 공간을 채우기 위해 아래로 내려갔으므로 그 자리는 0
                    }
                    
                    board[temp][j] = 'X';
                    
                    if (temp == 0) // 더이상 위에 남아있는 블럭이 없으므로 옆 칸으로 넘어간다.
                        break;
                }
            }
        }
    }
    
    return answer;
}
