/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/72412 (프로그래머스 Level 2)

지원자가 지원서에 입력한 4가지 정보(개발언어, 직군, 경력, 소울푸드)와 획득한 코딩테스트 점수를 하나의 문자열로 구성한다. 
개발팀은 주어진 조건에 모두 부합하는 지원자를 찾고 싶어하므로 자신들이 필요로 하는 조건들을 하나의 문자열로 구성한다.
지원서 정보 n개가 담긴 info 배열과 조건 m개가 담긴 query 배열이 주어질 때, 각 조건에 부합하는 사람들의 숫자를 배열에 담아 리턴하는 문제.

각 조건에 대해 n개의 정보를 모두 확인하는 방식은 O(nm)으로 효율성을 만족시킬 수 없다.
적절한 자료구조를 구현하면 더 효율적으로 구현할 수 있는데, 지원서 정보가 4개이므로 4차원 vector를 선언한다.
4차원 배열에 필요한 4가지 인덱스는 지원서에 입력한 4가지 정보를 이용하며, 지원자의 코딩테스트 점수를 해당 인덱스의 vector에 삽입한다.
예를 들어 개발언어의 경우 cpp는 0, java는 1, python은 2로 정수 인코딩을 해주고
만약 개발언어 정보가 cpp, 코딩테스트 점수가 150이라면 v[0][j][k][l]에 150을 삽입한다.
(i, k, l 역시 정수 인코딩으로 인덱스가 정해진다.)
각 조건들도 파싱 후 4가지 지원 조건에 대한 파싱 결과를 인덱스로 하여 지원 조건을 만족하는 vector들을 찾는다. 
(조건에 -가 하나도 없는 경우 조건을 만족하는 vector는 하나뿐이지만 -가 하나라도 있다면 조건을 만족하는 vector 역시 하나 이상이 된다.)
조건을 만족하는 각 vector들에 대해 삽입된 값들을 탐색하여 X점 이상인 원소를 찾는다.
이렇게 찾은 원소가 주어진 조건을 모두 만족하는 원소가 된다.
이때 만약 하나의 vector에 n개의 데이터가 모두 들어있다면 최악의 경우 한 번의 탐색에 O(n)이 걸려서 효율성 문제를 해결하지 못하므로 이진 탐색을 이용한다.
모든 vector들을 STL Sort로 정렬해준 후 이진 탐색 기반의 lower_bound를 이용하여 효율적인 방식으로 X점 이상인 원소의 수를 구할 수 있다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<int> v[3][2][2][2];
    
    for (string s : info) { // 지원서 정보 파싱
        int a, b, c, d, idx = 0;
        
        if (s[idx] == 'c') {
            a = 0;
            idx += 4;
        }
        else if (s[idx] == 'j') {
            a = 1;
            idx += 5;
        }
        else {
            a = 2;
            idx += 7;
        }
        
        if (s[idx] == 'b') {
            b = 0;
            idx += 8;
        }
        else {
            b = 1;
            idx += 9;
        }
        
        if (s[idx] == 'j') {
            c = 0;
            idx += 7;
        }
        else {
            c = 1;
            idx += 7;
        }
        
        if (s[idx] == 'c') {
            d = 0;
            idx += 8;
        }
        else {
            d = 1;
            idx += 6;
        }
        
        v[a][b][c][d].push_back(stoi(s.substr(idx))); // 지원자의 4가지 정보를 인덱스로 하며 코테 점수를 값으로 삽입
    }
    
    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                for(int l=0; l<2; l++)
                    sort(v[i][j][k][l].begin(),v[i][j][k][l].end());
    
    for (string s : query) { 
        int score, sum = 0, idx = 0;
        int a1, a2, b1, b2, c1, c2, d1, d2; 
        
        // 쿼리 정보 파싱
        if (s[idx] == 'c') {
            a1 = a2 = 0;
            idx += 8;
        }
        else if (s[idx] == 'j') {
            a1 = a2 = 1;
            idx += 9;
        }
        else if (s[idx] == 'p') {
            a1 = a2 = 2;
            idx += 11;
        }
        else {
            a1 = 0;
            a2 = 2;
            idx += 6;
        }
        
        if (s[idx] == 'b') {
            b1 = b2 = 0;
            idx += 12;
        }
        else if (s[idx] == 'f') {
            b1 = b2 = 1;
            idx += 13;
        }
        else {
            b1 = 0;
            b2 = 1;
            idx += 6;
        }
        
        if (s[idx] == 'j') {
            c1 = c2 = 0;
            idx += 11;
        }
        else if (s[idx] == 's') {
            c1 = c2 = 1;
            idx += 11;
        }
        else {
            c1 = 0;
            c2 = 1;
            idx += 6;
        }
        
        if (s[idx] == 'c') {
            d1 = d2 = 0;
            idx += 8;
        }
        else if (s[idx] == 'p') {
            d1 = d2 = 1;
            idx += 6;
        }
        else {
            d1 = 0;
            d2 = 1;
            idx += 2;
        }
        
        score = stoi(s.substr(idx)); // 점수 기준
        
        // 4가지 쿼리 조건에 모두 해당되는 배열을 대상으로 점수가 score 이상인 원소의 수 탐색
        for(int i = a1; i <= a2; i++) {
            for(int j = b1; j <= b2; j++) {
                for(int k = c1; k <= c2; k++) {
                    for(int l = d1; l <= d2; l++) {
                        auto it = lower_bound(v[i][j][k][l].begin(), v[i][j][k][l].end(), score);
                        if(it == v[i][j][k][l].end()) // score 이상인 원소(지원자)가 존재하지 X
                            continue;
                        
                        sum += v[i][j][k][l].size() - (it - v[i][j][k][l].begin());
                    }
                }
            }
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}
