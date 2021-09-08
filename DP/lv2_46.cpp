/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12905 (프로그래머스 Level 2)

1와 0로 채워진 표(board)에서 1로만 이루어진 가장 큰 정사각형의 넓이를 리턴하는 문제.

DP를 이용해서 풀어야 효율성 테스트까지 통과할 수 있다.
board 배열을 DP 테이블로 사용하며 (1, 1)에서부터 점차 값을 갱신해가면 된다.
갱신된 baord[i][j] 값은 오른쪽 아래 꼭짓점이 (i, j)인 정사각형들 중 가장 크기가 큰 정사각형의 한 변의 길이를 의미한다. 
예를 들어 board[3][3]이 3으로 갱신됐을 경우
(i, j)를 오른쪽 아래 꼭짓점으로 삼는 정사각형들 중 board[1][1], board[1][3], board[3][1], board[3][3]을 꼭짓점으로 삼는 정사각형이 가장 큰 정사각형임을 의미한다.
DP 테이블을 채우는 방식은 (i, j) 기준 바로 위, 왼쪽, 왼쪽 위 대각선 방향의 값들 중 가장 작은 값을 찾아 +1한 값으로 board[i][j]를 갱신하면 된다.
이러한 설계가 성립하는 이유는 (i, j)를 갱신할 때 (i - 1, j), (i, j - 1), (i - 1, j - 1)의 테이블 값을 기준으로 1이 보장되는 칸들의 영역을 따져보면 알 수 있다.
왼쪽 칸과 위쪽 칸의 테이블 값이 필요하므로 (0, 0)이 아닌 (1, 1)부터 오른쪽 아래 방향으로 테이블 갱신을 시작하며
<algorithm> 헤더의 min 함수는 원래 매개변수 2개를 받지만 비교할 매개변수가 3개 이상인 경우도 {}를 이용하여 배열로 묶어 넣어주면 min 함수 적용이 가능하다.

시간복잡도는 O(n^2)
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0]; // 테스트케이스가 모두 0인 경우까지 통과하려면 초기값을 0 또는 board[0][0]으로 초기화해줘야 한다.
    
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] == 1) {
                board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}
