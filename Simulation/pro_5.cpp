/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67256 (프로그래머스 Level 1)

왼손 엄지손가락과 오른손 엄지손가락을 이용하여 주어진 numbers 배열의 번호에 따라 스마트폰 키패드를 누른다.
각 번호를 누른 엄지손가락이 오른손인지 왼손인지를 연속된 문자열 형태로 return하는 문제.
사용 규칙은 다음과 같다.
1. 엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당한다.
2. 왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용한다.
3. 오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용한다.
4. 가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용한다.
 4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용한다.

스마트폰 키패드를 4 X 3 크기의 2차원 배열로 구현하였다. 
1번 키패드는 (1, 1), 4번 키패드는 (2, 1), ... 이런식으로 #을 포함하여 (4, 3)까지 구현한다.
입력 한 번이 끝날 때마다 왼손 또는 오른손 엄지손가락의 위치를 이 2차원 배열을 기준으로 저장해가며 시뮬레이션을 진행한다.

시간복잡도는 O(n)
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> L = {4, 1}, R = {4, 3}; // 키패드를 (1, 1)부터 (4, 3)까지의 4 X 3 배열로 보고 왼손과 오른손의 위치를 저장
    
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) { 
            answer += "L";
            L = {(num / 3 + 1), 1};
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            R = {(num / 3), 3};
        }
        else {
            if (num == 0)
                num = 11;
            pair<int, int> temp = {(num / 3 + 1), 2}; // 입력해야 되는 수의 배열 위치 계산
            
            int l_dist = abs(temp.first - L.first) + abs(temp.second - L.second); // 왼손과의 거리 계산
            int r_dist = abs(temp.first - R.first) + abs(temp.second - R.second); // 오른손과의 거리 계산
            
            if (l_dist > r_dist) {
                answer += "R";
                R = temp;
            }
            else if (l_dist < r_dist) {
                answer += "L";
                L = temp;
            }
            else { // 두 엄지손가락과의 거리가 같다면
                if (hand  == "left") {
                    answer += "L";
                    L = temp;
                }
                else {
                    answer += "R";
                    R = temp;
                }
            }
        }
    }
    
    return answer;
}
