/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12940 (프로그래머스 Level 1)

주어진 두 수의 최대공약수와 최소공배수를 구하는 문제.

최대공약수의 경우 처음에는 min(n, m)부터 1까지의 수에 대해 탐색하며 n과 m을 나눴을 때의 나머지가 모두 0인 수를 구하는 역순 탐색 방식을 이용하였다.
이러한 방식은 최악의 경우 O(min(n, m))의 시간복잡도를 갖는다.
유클리드 알고리즘을 이용하면 O(log (min(n ,m)))의 시간에 최대공약수를 구할 수 있다.
최소공배수의 경우 lcm(n, m) = n * m / gcd(n ,m)임을 이용하여 쉽게 구할 수 있다.
(최대공약수와 최소공배수 사이에 lcm(n, m) * gcd(n, m) = n * m 관계가 존재하기 때문)

참고 : 유클리드 호제법(유클리드 알고리즘)
- 유클리드 호제법은 2개의 자연수의 최대공약수를 구하는 알고리즘의 하나이다.
- 2개의 자연수 a, b에 대해 a를 b로 나눈 나머지를 r이라고 하면(r = a % b), gcd(a, b)가 gcd(b, r)과 같다는 성질을 이용한다. (이때, a > b)
-> a % b가 0이라면, gcb(a, b)는 b라는 것이 자명하다.
-> a % b가 0이 아니라면, 위에 언급한 성질을 이용하여 큰 수를 작은 수로 나눈 나머지가 0이될 때까지 gcd(a, b) -> gcd(b, r) -> gcb(r, r') -> ... 를 반복적으로 구한다. (r = a % b, r' = b % r)

시간복잡도는 위에 언급한 것처럼 O(log (min(n, m))) 
*/

#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if (n < m) {
        int temp = n;
        n = m;
        m = temp;
    }
    
    answer.push_back(gcd(n, m));
    answer.push_back(n * m / answer[0]);
    
    return answer;
}
