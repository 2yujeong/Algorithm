/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12924 (프로그래머스 Level 2)

자연수 n을 연속된 자연수들의 합으로 표현하는 방법의 개수를 구하는 문제.

처음에는 완전탐색을 생각했지만 연속된 자연수라는 부분을 생각하면 더 간단하게 풀 수 있다.
우선 n + 1의 절반이 되는 수는 두 번 더하면 n과 같거나 n보다 커져버린다.
따라서 2개 이상의 연속된 자연수들의 합으로 표현 가능한 구간은 1부터 (n + 1) / 2까지가 된다.
1부터 (n + 1) / 2까지, 수들을 하나씩 차례로 더해가며 그 합이 n과 같아지는 순간이 오면 answer 값을 하나 더해준다.
만약 i까지 더했을 때의 합이 n보다 커져버리면, n과 같거나 n보다 작아질 때까지 1부터 차례로 합에서 빼준다.
그러다가 n과 합이 같아지면 answer 값을 하나 더해주고 다시 i + 1번째 수부터 합에 더해주며 위의 과정을 반복한다.

시간복잡도는 i와 j가 각각 1부터 최대 n / 2까지 가므로 O(n)
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // n 자체도 정답에 포함되기 때문에 answer의 초기값은 1로 설정
    int sum = 0;
    
    for (int i = 1, j = 1; i <= (n + 1) / 2; i++) {
        sum += i;
        
        while (sum > n) {
            sum -= j;
            j++;
        }
        
        if (sum == n)
            answer++;
    }
    
    return answer;
}
