/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/81302 (프로그래머스 Level 2)

5 X 5 크기의 대기실이 5개가 있다.
각 대기실 별로 다음 조건에 따라 거리두기를 잘 지키고 있는지 판별하는 문제.
조건 1 - 응시자들이 앉은 자리 간의 맨해튼 거리가 2보다 커야 한다.
조건 2 - 두 응시자 사이가 파티션으로 막혀있는 경우에는 맨해튼 거리와 상관없이 허용한다.

문제를 풀기 위해, 거리두기를 지키지 못한 경우를 다음과 같이 두 가지로 나눌 수 있다.
1. 두 응시자가 서로의 바로 옆자리에 붙어 앉은 경우(맨해튼 거리가 1인 경우)
2. 한 응시자의 상하좌우 자리 중 하나와 다른 응시자의 상하좌우 자리 중 하나가 겹치는데 그 겹치는 자리가 빈 테이블일 때 (맨해튼 거리가 2이고 그 사이가 파티션으로 막혀있지 않은 경우)
따라서 각 대기실의 (0, 0) 위치부터 순차적으로 탐색하며 P가 나오면 해당 자리의 상하좌우 자리들을 기준으로 위 두 조건에 대해 판별한다.
만약 두 조건 중 하나라도 충족하면 거리두기를 지키지 않았다는 뜻이므로 바로 0을 리턴한다.

시간복잡도는 대기실의 크기, 대기실의 개수에 각각 선형적으로 의존한다.
*/

#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int check(vector<string>& v) {
    vector<vector<int> > used_table(5, vector<int> (5, 0)); // 자리 상태가 'O'(빈 테이블)인 자리들 중 겹치는 자리인 지를 판별하기 위한 배열
    
    for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (v[i][j] == 'P') {
                    for (int k = 0; k < 4; k++) {
                        int moved_i = i + dx[k];
                        int moved_j = j + dy[k];
                        
                        if (moved_i >= 0 && moved_i < 5 && moved_j >= 0 && moved_j < 5) {
                            if (v[moved_i][moved_j] == 'P') 
                                return 0;
                            else if (v[moved_i][moved_j] == 'O') {
                                if (used_table[moved_i][moved_j] == 1) // 전에 이미 한 번 방문했던 자리 -> 빈 테이블이면서 겹치는 자리이므로 0 리턴
                                    return 0;
                                else
                                    used_table[moved_i][moved_j] = 1; 
                            }
                        }
                    }
                }
            }
        }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> v : places) {
        answer.push_back(check(v));
    }
    
    return answer;
}
