/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/64061 (프로그래머스 Level 1)

뽑을 수 있는 인형들의 정보가 담긴 N x N 크기의 격자칸의 정보가 board 배열로 주어진다.
크레인을 이용하여 인형을 뽑는데 뽑힌 인형은 바구니에 한줄로 쌓이며 똑같은 종류의 인형이 연속으로 두 번 쌓이면 그 두 개의 인형은 터트려져서 사라진다.
크레인을 작동시킬 위치가 담긴 배열 moves가 주어질 때 크레인을 모두 작동시킨 후 사라진 인형의 개수를 return하는 문제.

스택을 바구니 정보를 구현하는 하나의 스택만 사용하면 격자칸의 각 위치별 남은 인형 정보를 구하기 위해 매번 맨 윗칸부터 탐색해야 한다.
N개의 스택을 추가로 선언하여 처음 board 배열의 정보를 각 스택으로 옮겨주는 작업만 하면 각 위치의 격자칸의 인형 정보를 실시간으로 업데이트하고 탐색할 수 있다.

시간복잡도는 board 배열의 크기가 n^2, moves 배열의 크기가 m일 때 O(n^2 + m)
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int n = board[0].size();
    stack<int> s[n + 1]; // 게임 화면에서 1번 ~ n번 위치의 각 칸들의 정보를 담는 스택
    stack<int> result; // 바구니
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[j][i] == 0)
                break;
            
            s[i + 1].push(board[j][i]); // n x n번째 칸부터 자신의 위치에 해당하는 스택에 자신의 정보(인형 번호) 저장
        }
    }
    
    for (int move : moves) { // 크레인 작동
        if (!s[move].empty()) { // 인형이 없는 곳에서 크레인을 작동시키면 아무 일도 일어나지 않으므로 인형이 있는 경우에만 동작
            if (result.empty()) // 바구니가 비어있는 경우
                result.push(s[move].top());
            else {
                if (s[move].top() == result.top()) { // 인형이 터뜨려지는 경우
                    answer += 2;
                    result.pop();
                }
                else
                    result.push(s[move].top());
            }
            
            s[move].pop(); // 뽑힌 인형은 스택에서 pop
        }
    }
    
    return answer;
}
