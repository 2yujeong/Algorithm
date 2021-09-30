/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/68645 (프로그래머스 Level 2)

밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후, 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 리턴하는 문제.

밑변의 길이와 높이가 n인 삼각형을 2차원 배열을 이용하여 구현하고 반시계 방향대로 달팽이 채우기를 진행했다.
2차원 배열에서의 인덱스는 x, y를 이용하여 아래로 내려갈 때는 x + 1, 오른쪽으로 갈 때는 y + 1, 위로 갈 때는 x - 1 식으로 좌표를 변경해주었다.
달팽이 채우기의 진행 방향은 아래로 채우기 -> 오른쪽으로 채우기 -> 위로 채우기가 반복되는데 수를 얼마나 채우고 진행 방향을 바꿀 지는 cnt 변수를 이용하였다.
문제에서 주어진 그림을 보면 다음과 같은 패턴으로 수 채우기를 진행한다.
n만큼 아래로 가며 채우기 -> n - 1만큼 오른쪽으로 가며 채우기 -> n - 2만큼 위로 가며 채우기 -> n - 3만큼 아래로 -> ... 
따라서 cnt의 값을 n부터 1씩 감소해가며 cnt만큼 수 채우기를 진행하면 진행 방향을 바꾸도록 해주었다.

시간복잡도는 1부터 n까지의 합이므로 O(n(n + 1) / 2) = O(n^2)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int> > v(n, vector<int> (n));
    
    int num = 1, cnt = n;
    int x = 0, y = 0;
    
    while (1) {
        for (int i = 0; i < cnt; i++) {
            v[x++][y] = num++;
        }
        
        cnt--;
        x--;
        y++;
        
        if (v[x][y] != 0)
            break;
        
        for (int i = 0; i < cnt; i++) {
            v[x][y++] = num++;
        }
        
        cnt--;
        y -= 2;
        x--;
        
        if (v[x][y] != 0)
            break;
            
        for (int i = 0; i < cnt; i++) {
            v[x--][y--] = num++;
        }
        
        cnt--;
        x += 2;
        y++;
        
        if (v[x][y] != 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}
