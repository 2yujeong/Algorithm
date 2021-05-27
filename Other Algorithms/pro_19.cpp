/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12921 (프로그래머스 Level 1)

1부터 n 사이에 있는 소수의 개수를 return하는 문제.
에라토스테네스의 체를 활용하여 풀었다.

시간복잡도는 에라토스테네스의 체의 시간복잡도인 O(nlog(log n))
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> prime(n + 1, 1);
    int cnt = n - 1;
    
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 0)
            continue;
        
        for (int j = i + i; j <= n; j += i) {
            if (prime[j] != 0) {
                cnt--;
                prime[j] = 0;
            }
        }
    }
    
    return cnt;
}
