/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/68936 (프로그래머스 Level 2)

0과 1로 이루어진 2^n X 2^n 크기의 배열 arr을 쿼드 트리와 같은 방식으로 압축하려고 한다.
 1. 압축하고자 하는 특정 영역을 S라고 정의한다.
 2. 만약 S 내부에 있는 모든 수가 같은 값이라면, S를 해당 수 하나로 압축시킨다.
 3. 그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역으로 쪼갠 뒤, 각 정사각형 영역에 대해 같은 방식의 압축을 시도한다.
압축 후 배열에 최종적으로 남는 0의 개수와 1의 개수를 리턴하는 문제.

재귀함수를 이용하여 문제에서 주어진 압축 방법을 그대로 구현해주면 쉽게 풀 수 있다.
주어진 영역에 대해 모든 배열 값을 탐색하고 모두 0 또는 모두 1이 아니라면 해당 영역을 4개의 정사각형 영역으로 쪼개 각각 재귀함수를 돌린다.
주어진 영역이 모두 0 또는 모두 1이라면 해당 영역에 대해서는 더이상 재귀함수를 돌릴 필요가 없으므로 answer 배열에서의 0 또는 1의 개수를 하나 올려준다.

시간복잡도는 arr의 행의 길이가 n일 때 O(n^2((log(4) n^2) + 1))
*/

#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);

void compression(vector<vector<int>>& arr, int start_i, int start_j, int size) {
    int n = arr[start_i][start_j];
    
    for (int i = start_i; i < start_i + size; i++) {
        for (int j = start_j; j < start_j + size; j++) {
            if (arr[i][j] != n) {
                compression(arr, start_i, start_j, size / 2);
                compression(arr, start_i + size / 2, start_j, size / 2);
                compression(arr, start_i, start_j + size / 2, size / 2);
                compression(arr, start_i + size / 2, start_j + size / 2, size / 2);
                
                return;
            }
        }
    }
    
    answer[n]++;
}

vector<int> solution(vector<vector<int>> arr) {
    compression(arr, 0, 0, arr.size());
    
    return answer;
}
