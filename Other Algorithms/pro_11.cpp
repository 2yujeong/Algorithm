/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12982 (프로그래머스 Level 1)

n개의 각 부서들이 신청한 지원 물품 개수가 담긴 d 배열과 회사의 예산 budget이 주어진다. 
최대한 많은 부서에 물품을 지원해주려고 할 때 몇 팀의 부서까지 지원해줄 수 있는지 구하는 문제.

처음에 너무 복잡하게 생각해서 시간이 많이 걸렸던 문제로 조합 문제인 줄 알고 풀었다. 
조합 알고리즘을 n번 돌려서 원소들의 합이 budget보다 작아지면 그 때의 원소의 개수를 return 했는데 당연히 시간 초과가 떴다. 
훨씬 단순하게 생각해서 sort를 이용하면 쉽게 풀 수 있다.

시간복잡도는 STL sort()로 인해 O(nlog n)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int amount = 0;
    
    sort(d.begin(), d.end());
    
    for (int i = 0; i < d.size(); i++) {
        if (amount + d[i] > budget)
            break;
        
        amount += d[i];
        answer++;
    }
    
    return answer;
}
