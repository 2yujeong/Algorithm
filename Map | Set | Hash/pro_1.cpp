/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/1845 (프로그래머스 Level 1)

N마리의 폰켓몬의 번호가 주어진다. 번호가 같으면 같은 종류의 폰켓몬이며 그 중 N / 2마리의 폰켓몬을 선택하려고 한다. 
가장 많은 종류의 폰켓몬을 선택할 때의 그 종류의 개수를 출력하는 문제.

주어진 배열(N마리의 폰켓몬의 번호)에서 중복을 제거했을 때 남는 원소의 개수가 N / 2가 넘는지 안 넘는지에 따라 답을 찾을 수 있다.
중복 제거를 위해 STL map 자료구조를 사용하여 map의 크기로 정답을 구하였다.

시간복잡도는 주어진 배열을 탐색하여 map에 넣어야 하므로 O(n)
*/

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, int> m;
    
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }
    
    if (m.size() >= nums.size() / 2)
        answer = nums.size() / 2;
    else
        answer = m.size();
    
    return answer;
}
