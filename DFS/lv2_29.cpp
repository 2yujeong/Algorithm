/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42839 (프로그래머스 Level 2)

n 길이의 숫자로 이루어진 문자열이 주어진다.
n개의 숫자로 만들 수 있는 모든 소수의 개수를 구하는 문제.

소수 판별은 에라토스테네스의 체를 이용했다.
에라토스테네스의 체는 주어진 범위 만큼의 수에 대해 소수인지 아닌지 미리 판별해놓는 알고리즘이므로 그 범위가 작을 수록 수행시간이 줄어든다.
따라서 주어진 문자열에 포함된 수들로 만들 수 있는 가장 큰 수를 미리 구하고 그 수까지만 소수 판별을 해놓으면 시간을 많이 단축시킬 수 있다.
완전탐색은 dfs를 이용하여 구현하였으며 주어진 문자열의 숫자들로 만들 수 있는 모든 수에 대해 앞서 구해놓은 prime 배열을 이용하여 소수인지 판별한다.
이때 문자열에 같은 숫자가 여러 개 포함되어 있으면 똑같은 수가 2번 이상 판별되는 경우가 생기므로 이를 방지하기 위해 이미 한 번 판별된 수는 체크해놓는 map 배열을 이용하였다.

시간복잡도는 완전탐색이 지수시간의 시간복잡도가 걸리지만 이 문제는 에라토스테네스의 체를 이용하여 구하는 소수 판별 범위에 더 의존적이다.
참고로 에라토스테네스의 체의 시간복잡도는 일반적으로 O(nlog(log n))이 걸린다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map; // 똑같은 수가 2번 이상 중복으로 소수 판별되는 걸 방지하기 위한 배열
vector<int> check(7, 0); // dfs 진행을 위한 check 배열
int answer = 0;

void dfs(int level, int value, string& numbers, vector<int>& prime) {
    if (level == numbers.length())
        return;
    
    for (int i = 0; i < numbers.length(); i++) {
        if (check[i] == 0) {
            check[i]++;
            int new_val = value * 10 + (numbers[i] - '0');
            dfs(level + 1, new_val, numbers, prime);
            check[i]--;
            
            if (prime[new_val] && map[new_val] == 0)
                answer++;
                map[new_val] = 1;
        }
    }
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end(), greater<int>());
    int num = stoi(numbers);
    map.resize(num + 1);
    
    vector<int> prime(num + 1, 1); // 소수인지 판별하기 위한 배열(합성수면 0, 소수면 1)
    prime[0] = 0;
    prime[1] = 0;
    
    // 에라토스테네스의 체
    for (int i = 2; i * i < prime.size(); i++) {
        if (prime[i] == 0)
            continue;
        
        for (int j = i + i; j < prime.size(); j += i) {
            prime[j] = 0;
        }
    }
    
    dfs(0, 0, numbers, prime);
    
    return answer;
}
