/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/86491 (프로그래머스 Level 1)

여러 개의 명함의 가로 길이와 세로 길이가 담긴 2차원 배열이 매개변수로 주어진다.
모든 명함을 수납할 수 있는 가장 작은 크기의 지갑을 만든다고 할 때, 지갑의 크기를 리턴하는 문제.

각 명함의 가로 길이와 세로 길이를 비교하여 더 큰 값을 가로 길이, 더 작은 값을 세로 길이로 가정한다.
명함들의 가로 길이끼리 비교하여 그 중 최댓값을 w_max에, 세로 길이끼리 비교하여 그 중 최댓값을 h_max에 저장하면 가로, 세로별로 가장 큰 길이값을 구할 수 있다.
이렇게 구한 두 값을 곱해서 리턴해준다. 

시간복잡도는 O(n)
*/

#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w_max = 0;
    int h_max = 0;
    
    for (vector<int> v : sizes) {
        w_max = max(w_max, max(v[0], v[1]));
        h_max = max(h_max, min(v[0], v[1]));
    }
    
    return answer = w_max * h_max;
}
