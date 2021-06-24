/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/77485 (프로그래머스 Level 2)

1부터 rows x columns까지의 숫자가 한 줄씩 순서대로 적혀있는 rows x columns 크기의 행렬이 있다.
(x1, y1, x2, y2)이 주어지면 이 행렬에서 x1 행 y1 열부터 x2 행 y2 열까지의 영역에 해당하는 직사각형에서 테두리에 있는 숫자들을 한 칸씩 시계방향으로 회전한다.
rows, columns, 회전들의 목록 queries가 주어질 때, 각 회전들을 배열에 적용한 뒤 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 하는 문제.

주어진 회전 범위의 윗변, 왼쪽변, 아랫변, 오른쪽변 순서대로 숫자가 회전하는 시뮬레이션을 구현하였다.
처음 map 배열 초기화에 오류가 있어서 3번 테스트 케이스부터 통과하지 못했는데 i * rows + j + 1를 i * columns + j + 1로 정정해줌으로써 해결했다.

시간복잡도는 queries의 크기가 n이라고 할 때 O(rows * columns + n(rows + columns))
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    if (queries.size() == 1) { // query가 하나인 경우는 시뮬레이션 할 필요 X
        answer.push_back((queries[0][0] - 1) * columns + queries[0][1]);
        return answer;
    }
    
    vector<vector<int>> map(rows, vector<int> (columns)); // 직사각형(map) 생성
    
    for (int i = 0; i < rows; i++) { // map 초기화
        for (int j = 0; j < columns; j++) {
            map[i][j] = i * columns + j + 1;
        }
    }
    
    for (int a = 0; a < queries.size(); a++) { // 시뮬레이션
        int i = queries[a][0] - 1, j = queries[a][3] - 1;
        int temp = map[i][j];
        int _min = temp;
        
        for (; j > queries[a][1] - 1; j--) {
            map[i][j] = map[i][j - 1];
            _min = min(_min, map[i][j]);
        }
        
        j = queries[a][1] - 1;
        for (i = queries[a][0] - 1; i < queries[a][2] - 1; i++) {
            map[i][j] = map[i + 1][j];
            _min = min(_min, map[i][j]);
        }
        
        i = queries[a][2] - 1;
        for (j = queries[a][1] - 1; j < queries[a][3] - 1; j++) {
            map[i][j] = map[i][j + 1];
            _min = min(_min, map[i][j]);
        }
        
        j = queries[a][3] - 1;
        for (i = queries[a][2] - 1; i > queries[a][0]; i--) {
            map[i][j] = map[i - 1][j];
            _min = min(_min, map[i][j]);
        }
        
        map[i][j] = temp;
        answer.push_back(_min);
    }
    
    return answer;
}
