/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/49994 (프로그래머스 Level 2)

게임 캐릭터는 U, D, R, L 4가지 명령어를 통해 움직이며 각각 위쪽, 아래쪽, 오른쪽, 왼쪽으로 한 칸 이동을 의미한다.
주어진 명령에 따라 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 리턴하는 문제.
게임 캐릭터는 좌표평면의 0, 0에서 움직이기 시작하며 좌표평면의 경계를 넘어가는 명령어는 무시한다.
좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있다.

10 X 10 크기의 좌표평면을 의미하는 2차원 배열 map을 선언한다.
캐릭터는 처음 (5, 5) 위치에서 움직이기 시작하며 만약 (i, j)번째 위치에서 U / D / R / L로 움직였다면 map[i][j]에 U / D / R / L을 저장한다.
(i, j)에서 한 번 움직일 때마다 map[i][j]를 탐색하여 방금 움직인 방향과 같은 방향으로 이미 움직인 적이 있는지 판별하고
움직인 적이 없다면 방금 움직인 방향을 map[i][j]에 넣어준 뒤 처음 걸어본 길이라는 의미로 answer 값을 하나 더해준다.
처음 구현했을 때 반 이상의 테스트케이스를 통과하지 못했는데
똑같은 길을 왼쪽->오른쪽 / 위->아래로 움직일 때와 오른쪽->왼쪽 / 아래->위로 움직일 때를 서로 다른 길이라고 판별했기 때문이었다.
예를 들어 (1, 1)에서 (2, 1)로 올라가는 경우나 (2, 1)에서 (1, 1)로 내려오는 경우 방향은 다르지만 걷는 길은 똑같다.
이러한 경우를 유의해서 풀면 테스트케이스를 모두 통과할 수 있다.

시간복잡도는 명령어가 4개 뿐이므로 map[i][j]를 이용해 이미 걸었던 길인지 판별하는 과정이 상수 시간이 걸린다.
따라서 dirs의 크기에만 의존하므로 O(n)이 시간복잡도가 된다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    vector<char> map[11][11];
    int i = 5, j = 5;
    
    for (char c : dirs) {
        int old_i = i, old_j = j; // 움직이기 전 위치 저장
        char reverse; // 하나의 길을 서로 다른 방향으로 건너는 경우도 같은 움직임으로 판별하기 위해 반대 방향까지 저장
        
        if (c == 'U' && i > 0) {
            i--;
            reverse = 'D';
        }
        else if (c == 'D' && i < 10) {
            i++;
            reverse = 'U';
        }
        else if (c == 'R' && j < 10) {
            j++;
            reverse = 'L';
        }
        else if (c == 'L' && j > 0) {
            j--;
            reverse = 'R';
        }
        else 
            continue;
        
        int flag = 0;
        
        for (int k = 0; k < map[old_i][old_j].size(); k++) { // 겹치는 경로인지 확인
            if (map[old_i][old_j][k] == c) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) { // 겹치는 경로가 아니라 처음 걸어본 길이라면
            map[old_i][old_j].push_back(c); // old_i, old_j 좌표에서 c 방향으로 이동했다는 것을 기록
            map[i][j].push_back(reverse); // 그 반대인 i, j에서 old_i, old_j로 이동하는 길도 같은 길이므로 처리해준다.
            answer++;
        }
    }
    
    return answer;
}
