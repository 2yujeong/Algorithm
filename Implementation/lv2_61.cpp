/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/92335 (프로그래머스 Level 2)

양의 정수 n을 k진수로 바꿨을 때, 변환된 수 안에 존재하는 소수의 개수를 구하는 문제.

우선 n을 k진수로 변환하기 위해, n을 k로 나눈 나머지를 string 변수에 뒤에서부터 앞 방향으로 계속 붙여준다.
그 다음 변환된 수를 0을 기준으로 구간을 나눈 뒤 각 구간별로 소수인지 아닌지를 판별하는 과정을 진행한다.
이때 n과 k의 범위를 생각하면 하나의 구간이 int 형의 범위를 벗어날 수 있으므로 long long 형을 쓰는 것에 유의해야 한다.

소수 판별의 경우 에라토스테네스의 체를 생각할 수 있지만,
이 문제는 하나의 테스트 케이스에서 소수인지 아닌지 판별해야 하는 수들의 개수가 많지 않고
판별이 필요한 하나의 수의 크기가 int 형을 벗어날 정도로 매우 클 수 있으므로 
가능한 모든 범위에 대해 변환 결과를 미리 배열에 저장해놓는 에라토스테네스의 체 방식은 적절하지 않다. 
*/

#include <string>
#include <vector>

using namespace std;

int isPrime(long long num) {
    if (num == 1)
        return 0;
    
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = "";
    while (n > 0) {
        num = to_string(n % k) + num;
        n /= k;
    }
    
    string temp = "";
    for (int i = 0; i <= num.length(); i++) {
        if (i != num.length() && num[i] != '0') {
            temp += num[i];
            continue;
        }
        
        if (temp.length() > 0)
            answer += isPrime(stoll(temp));
        temp = "";
    }
    
    return answer;
}
