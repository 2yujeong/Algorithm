/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12913 (프로그래머스 Level 2)

땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 모든 칸에는 점수가 쓰여 있다. 
1행부터 땅을 밟으며 한 행씩 내려올 때, 각 행의 4칸 중 한 칸만 밟으면서 내려와야 하며 같은 열을 연속해서 밟을 수 없다.
마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 리턴하는 문제.

처음에는 그리디한 방법으로 각 행에서의 최댓값을 구하고 이전 행의 최댓값의 인덱스와 비교하여 다르면 더해주는 방식으로 풀었다.
문제에 직접 주어진 입출력 예시는 만족했지만, 다음과 같은 경우 때문에 채점용 테스트케이스를 모두 실패했다.
| 1 | 2 | 3 | 5 |
| 5 | 6 | 7 | 10 |
| 4 | 3 | 2 | 1 |
이 경우 그리디한 방식으로 풀면 5 + 7 + 4 = 16이 나오지만 정답은 3 + 10 + 4 = 17로 17이 최대 점수가 된다.
또한 같은 행에 중복되는 값들이 주어지는 경우에도 원하는 답을 얻지 못할 수 있다.
따라서 이 문제는 모든 경우에 대해 최댓값을 구해야 하는 문제로, DP를 이용해서 풀어야 한다.

[DP 테이블 설계]
입력으로 주어진 land 테이블을 DP 테이블로 활용하여 값을 갱신해 나간다.
land[i][j]는 i번째 행의 j번째 열을 밟을 때까지 얻을 수 있는 최대 점수를 의미한다.
j번째 열을 밟으려면 바로 윗행, 즉 i - 1번째 행에서는 j열을 밟으면 안 되므로
land[i - 1]행의 4개의 열들 중 j열을 제외한 3개의 열들에 대해 최댓값을 찾아 land[i][j]에 더해주면 
첫 행부터 i행 j열까지 오는 데에 얻을 수 있는 최대 점수가 land[i][j]에 저장된다.

위에서 언급한 예시에 대해 DP 테이블을 채우면 다음과 같은 상태가 된다.
| 1 | 2 | 3 | 5 |
| 10 | 11 | 12 | 13 |
| 17 | 16 | 15 | 13 |

시간복잡도는 O(n)
*/

#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for (int i = 0; i < land.size() - 1; i++) {
        land[i + 1][0] += max({land[i][1], land[i][2], land[i][3]});
        land[i + 1][1] += max({land[i][0], land[i][2], land[i][3]});
        land[i + 1][2] += max({land[i][0], land[i][1], land[i][3]});
        land[i + 1][3] += max({land[i][0], land[i][1], land[i][2]});
    }
    
    for (int i = 0; i < land[land.size() - 1].size(); i++) {
        answer = max(answer, land[land.size() - 1][i]);
    }

    return answer;
}
