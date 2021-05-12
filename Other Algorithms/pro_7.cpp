/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42840 (프로그래머스 Level 1)

3명의 수포자가 다음과 같은 패턴으로 수학 문제에 대한 답을 찍는다.
1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
정답 배열 answer가 주어졌을 때 가장 많은 문제를 맞힌 사람의 번호를 return하는 문제.

3명의 수포자가 정답을 찍는 패턴을 저장하는 arr 배열을 선언하고 각각의 포인터를 이용하여 문제를 풀었다.

시간복잡도는 O(3n)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 3명의 수포자가 정답을 찍는 패턴을 저장한 정답 배열
    int arr[3][5] = {{1, 2, 3, 4, 5},
                     {2, 1, 3, 4, 5},
                     {3, 1, 2, 4, 5}};
    
    int p[3] = {0, 0, 0}; // 각 수포자의 정답 배열을 가리킬 포인터
    int c[3] = {0, 0, 0}; // 수포자별로 맞힌 문제수 저장
    
    int count = 1;
    int tmp = 0;
    
    for (int answer : answers) {
        for (int i = 0; i < 3; i++) { // 각 수포자별로 정답을 맞았는지 판별
            if (arr[i][p[i]] == answer)
                c[i]++;
        }
        
        p[0] = ++p[0] % 5; // 1번 수포자의 포인터 1 증가
        
        if (count % 2 != 0) { // 다음 문제가 짝수번 문제이면 2번 수포자의 포인터 1 증가
            p[1] = ++tmp;
            if (p[1] == 5)
                p[1] = 1;
        }
        else { // 다음 문제가 홀수번 문제이면 2번 수포자는 무조건 답을 2번으로 찍고 3번 수포자는 포인터 1 증가 
            tmp = p[1];
            p[1] = 0;
            
            p[2] = ++p[2] % 5;
        }
        
        count++;
        }
    
    // 맞힌 문제 수의 최댓값 찾기
    int max = -1;
    for (int i = 0; i < 3; i++) {
        if (c[i] > max)
            max = c[i];
    }
    
    // 최댓값만큼 맞힌 수포자의 번호 저장
    for (int i = 0; i < 3; i++) {
        if (c[i] == max)
            answer.push_back(i + 1);
    }
    
    return answer;
}
