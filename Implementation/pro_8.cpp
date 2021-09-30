/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/77484 (프로그래머스 Level 1)

자신이 찍은 로또 번호 중 알아볼 수 없는 수가 몇 개 존재할 때, 당첨 번호와 비교하여 자신의 가능한 최고 순위와 최저 순위를 구하는 문제.

시간복잡도는 O(1)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int max_match = 0, min_match = 0; // 각각 최대 / 최소로 맞혔을 경우의 일치한 번호 수
    
    for (int i = 0; i < 6; i++) {
        num[lottos[i]]++;
    }
    
    for (int win_num : win_nums) {
        if (num[win_num] == 0 && num[0] > 0) { // 확실하게 찍은 번호와 일치하지는 않지만, 최고 순위를 알기 위해 알아볼 수 없는 번호가 해당 번호라고 가정
            num[0]--;
            max_match++;
        }
        else if (num[win_num] > 0) { // 확실하게 찍은 번호와 당첨 번호가 일치한 경우
            max_match++;
            min_match++;
        }
    }
    
    answer.push_back(min(7 - max_match, 6));
    answer.push_back(min(7 - min_match, 6));
    
    return answer;
}
