/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12950 (프로그래머스 Level 1)

2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 리턴하는 문제.
2차원 배열의 구조만 잘 알고 있다면 어렵지 않게 풀 수 있다.

시간복잡도는 주어진 배열의 행의 길이가 n, 열의 길이가 m일때 O(nm)
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> temp;
        
        for (int j = 0; j < arr1[0].size(); j++) {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}
