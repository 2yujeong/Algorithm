/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42748 (프로그래머스 Level 1)

배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하는 문제.
STL sort를 이용해서 풀었다. 

시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) { 
        vector<int> v;
        
        for (int j = commands[i][0]; j <= commands[i][1]; j++) {
            v.push_back(array[j - 1]);
        }
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[commands[i][2] - 1]);
    }
    
    return answer;
}
