/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12899 (프로그래머스 Level 2)

124 나라에서는 10진법의 수를 다음과 같은 규칙으로 변환하여 표현한다.
10진법    124 나라
---------------------
1	1	
2	2	
3	4	
4	11	
5	12	
6	14
7	21
8	22
9	24
10	41
주어진 수 n을 124 나라의 수로 변환하여 리턴하는 문제.

1, 2, 4 총 3개의 수를 이용하여 변환하므로 3진법을 이용한 규칙을 찾으면 풀 수 있다. 
3진법에서는 1, 2, 0만 존재하지만 124 나라에서는 1, 2, 4만 존재한다.
따라서 3진법으로 변환했을 때의 수가 1 또는 2가 나오는 경우는 그대로 적용되며 0인 경우만 따로 처리해주면 된다. 
변환 과정에서 0이 나오면 4로 바꿔주고 dividend는 1을 빼준 후 변환 과정을 계속 진행한다.

시간복잡도는 3진법을 이용하면 O(log(3) n)으로 O(n)보다 빠르기 때문에 효율성 테스트를 통과할 수 있다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> v;
    
    while (n > 2) {
        if (n % 3 == 0) {
            answer = "4" + answer;
            n = n / 3 - 1;
        }
        else {
            answer = to_string(n % 3) + answer;
            n /= 3;
        }
    }
    
    if (n > 0)
        answer = to_string(n) + answer;
    
    return answer;
}
