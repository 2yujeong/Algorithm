/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/1835 (프로그래머스 Level 2)

단체사진을 찍기 위해 8명의 프렌즈들이 일렬로 나란히 선다.
프렌즈들이 서는 순서에 대한 특정 조건들이 입력으로 주어질 때, 이 조건을 만족할수 있도록 서는 경우의 수를 계산하는 문제.

DFS를 이용한 순열탐색을 구현하여 풀 수 있다.
8명이 나란히 서는 모든 경우에 대해 주어진 조건을 만족하는지 판별한다. 

시간복잡도는 전체 순열에 대해 탐색하므로 O(n!)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
string friends;
vector<char> result(8);
int check[8];

void dfs(vector<string>& data, int n) { // 모든 순열을 찾기 위한 DFS
    if (n == 8) { // 하나의 수열이 완성되면 조건에 부합하는지 판별
        for (int i = 0; i < data.size(); i++) {
            // 조건에 해당되는 프렌즈들의 위치(index)를 find()로 찾고 그 차이를 저장
            int idx = find(result.begin(), result.end(), data[i][0]) - find(result.begin(), result.end(), data[i][2]);
            
            // 조건을 한 번이라도 만족하지 못하면 break하고 그대로 for문을 빠져나온다.
            if (data[i][3] == '=' && abs(idx) != data[i][4] - '0' + 1) 
                break;
            else if (data[i][3] == '>' && abs(idx) <= data[i][4] - '0' + 1) 
                break;
            else if (data[i][3] == '<' && abs(idx) >= data[i][4] - '0' + 1)
                break;
            
            if (i == data.size() - 1) // 모든 조건을 만족한 경우 
                answer++;
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            result[n] = friends[i];
            dfs(data, n + 1);
            check[i] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    // 전역변수 초기화
    answer = 0;
    friends = "ACFJMNRT";
    for (int i = 0; i < 8; i++) {
        check[i] = 0;
        result[i] = 0;
    }
    
    dfs(data, 0);
    
    return answer;
}
