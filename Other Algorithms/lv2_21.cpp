/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42842 (프로그래머스 Level 2)

카펫의 테두리의 격자들은 갈색으로, 나머지 격자들은 노란색으로 칠해져있다.
갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 리턴하는 문제.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 3; ; i++) {
        for (int j = i; ; j++) {
            if ((i - 1) * 2 + (j - 1) * 2 == brown && (i - 2) * (j - 2) == yellow) {
                answer.push_back(j);
                answer.push_back(i);
                
                return answer;
            }
            
            if ((i - 1) * 2 + (j - 1) * 2 > brown || (i - 2) * (j - 2) > yellow) 
                break;
        }
    }
    
    return answer;
}
