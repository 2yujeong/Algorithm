/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/92342 (프로그래머스 Level 2)

라이언과 어피치가 양궁대회 결승에 출전한다.
어피치가 n발을 다 쏜 후 라이언이 n발을 쏘며, 다음과 같은 규칙에 따라 얻은 점수를 계산하여 더 높은 최종 점수를 얻은 선수가 우승한다.
 - 만약 k(k는 1~10사이의 자연수)점을 어피치가 a발을 맞혔고 라이언이 b발을 맞혔을 경우 더 많은 화살을 k점에 맞힌 선수가 k 점을 가져간다. 
 - 단, a = b일 경우는 어피치가 k점을 가져간다.
 -  a = b = 0 인 경우, 즉, 라이언과 어피치 모두 k점에 단 하나의 화살도 맞히지 못한 경우는 어느 누구도 k점을 가져가지 않는다.
라이언이 가장 큰 점수 차이로 우승하기 위해 n발의 화살을 어떤 과녁 점수에 맞혀야 하는지를 10점부터 0점까지 순서대로 정수 배열에 담아 리턴하는 문제.
만약 라이언이 우승할 수 없는 경우(무조건 지거나 비기는 경우)에는 -1을 리턴한다.

완전탐색을 이용하여 라이언이 가장 높은 점수차로 이기는 경우를 찾아야 한다.
10점 과녁부터 시작하여
 1. 라이언이 (어피치가 맞힌 화살의 개수 + 1)개의 화살을 과녁에 맞혀서 해당 과녁 점수를 가져가는 경우
 2. 라이언이 한 발도 맞히지 않고 다음 과녁으로 넘어가는 경우
  - 어피치가 1발 이상을 맞혀서 어피치가 해당 과녁 점수를 가져가는 경우
  - 둘 다 한 발도 맞히지 못해서 어느 누구도 해당 과녁 점수를 가져가지 못하는 경우
각 k점 과녁마다 위와 같은 2가지 경우로 뻗어가며 깊이탐색을 진행하였다.
라이언은 남은 화살의 개수가 많을수록 이길 가능성이 커지기 때문에
1번의 경우에는 딱 (어피치가 맞힌 화살 개수 + 1개)의 화살만 맞혀서 이겨야 하며
2번의 경우에는 어차피 이길 수 없기 때문에 한 발도 맞히지 않고 넘어간다.

문제를 풀면서 유의할 점은 라이언이 최대의 점수차로 우승하는 방법이 여러가지가 있을 수 있는데, 그중 가장 낮은 점수를 더 많이 맞힌 경우가 정답이 된다는 것이다.
따라서 1번 경우에 대한 탐색을 2번 경우에 대한 탐색보더 먼저 실행해줘야 한다.
2번 경우가 1번 경우보다 낮은 점수를 더 많이 맞힐 수 있는 방법이기 때문이다.
또한 한 번의 탐색이 끝날 때마다 둘의 점수차가 최대이면서 이전에 찾아놓은 또다른 방법의 점수차와 같다면, 
각 방법에서의 라이언의 점수를 비교하여 가장 낮은 점수를 더 많이 맞힌 경우를 찾아줘야 한다.

시간복잡도는 O(2^n)
*/

#include <string>
#include <vector>
using namespace std;

vector<int> answer; // 라이언의 경기 결과를 담을 정답 배열
vector<int> apeach_result; // 어피치의 경기 결과를 저장하고 있는 배열
int max_dif = 0; // 라이언이 이긴 경우에 라이언과 어피치의 점수차 중 가장 큰 값을 저장

void dfs(int apeach, int lion, int n, int left_arrow, vector<int>& result) {
    if (n == -1) { // 라이언이 10점 과녁부터 0점 과녁까지 모든 과녁에 대해 경기를 마쳤으므로 탐색을 끝낸댜.
        result[10] += left_arrow; // 동일한 점수차로 이겼을 때 가장 낮은 점수를 많이 맞힌 경우가 정답이 되므로 남은 화살은 0점을 맞히도록 처리
        
        if (lion > apeach && lion - apeach >= max_dif) { // 라이언의 총점이 더 높은 경우
            if (lion - apeach == max_dif) { // 동일한 점수차라면
                for (int i = 10; i > 0; i--) {
                    if (answer.empty() || answer[i] < result[i]) // 가장 낮은 점수를 더 많이 맞힌 경우가 정답
                        break;
                    if (answer[i] > result[i])
                        return;
                }
            }
            
            max_dif = lion - apeach; // 최대 점수차 값 갱신
            answer = result;
        }
        
        return;
    }
    
    if (apeach_result[10 - n] < left_arrow) { // 라이언이 어피치보다 n점 과녁을 더 많이 맞히는 경우
        result[10 - n] = apeach_result[10 - n] + 1; // 어피치보다 딱 한 발만 더 많이 맞혀도 이긴다.
        dfs(apeach, lion + n, n - 1, left_arrow - (apeach_result[10 - n] + 1), result); // 라이언의 점수가 n점 올라가고, 남은 화살의 개수가 n점 과녁을 맞힌 화살의 개수만큼 차감된다.
    }
    
    result[10 - n] = 0; // 라이언이 n점 과녁에는 화살을 한 발도 맞히지 않고 넘어가는 경우
    if (apeach_result[10 - n] != 0)
        dfs(apeach + n, lion, n - 1, left_arrow, result); // 어피치가 n점 과녁을 더 많이 맞혔으므로 어피치의 점수가 n점 올라간다.
    else // 둘 다 n점 과녁에 한 발도 맞히지 못한 경우
        dfs(apeach, lion, n - 1, left_arrow, result); // 둘 다 점수를 얻지 못한다.
}

vector<int> solution(int n, vector<int> info) {
    apeach_result = info;
    vector<int> result(11);
    
    dfs(0, 0, 10, n, result);
    
    if (answer.empty()) // 라이언이 이기는 경우의 수가 존재하지 않는 경우
        answer.push_back(-1);
    
    return answer;
}
