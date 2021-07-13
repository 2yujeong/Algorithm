/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42883 (프로그래머스 Level 2)

어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려고 한다.
이때 남은 수들의 자리는 서로 바꿀 수 없다.
예를 들어 529에서 2를 빼면 59는 만들 수 있지만 95는 만들 수 없다.

처음에는 DFS를 이용한 조합탐색 문제로 접근했다.
주어진 문자열에서 k개의 수를 뺀 숫자들 중 가장 큰 숫자를 구하는 방식이었는데 
입력의 크기가 워낙 크다보니(최대 1,000,000 자리의 수) 1, 11, 12번을 제외한 모든 테스트 케이스에서 런타임 에러가 났다.
앞 자리에 위치한 수가 클수록 큰 수가 된다는 사실을 이용하면 다음과 같이 스택을 이용하여 더 빠르게 풀 수 있다.
앞에서부터 작아서 빼야하는 수를 찾아 빼는 방식인데 이런 식으로 k개를 모두 빼면 뒤에 남아있는 수들은 탐색하지 않아도 된다.
언급한 것처럼 앞 자리에 위치한 수가 클수록 큰 수가 되기 때문이다.

시간복잡도는 O(n), n은 문자열 number의 길이
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int result_size = number.length() - k;
    stack<int> s;
    
    for (char n : number) {
        // 현재 들어갈 숫자보다 스택의 top이 더 작은 경우 스택에서 pop해준다. 
        while (!s.empty() && k > 0 && s.top() < n - '0') { 
            s.pop();
            k--; // k개의 수만 빼면 된다.
        }
        
        s.push(n - '0');
    }
    
    // 98765... 처럼 뒷자리로 갈수록 작아지는 수의 경우 k개 이하의 수를 빼게 될 수 있다.
    // -> 앞자리의 수가 클수록 큰 수이므로 맨 뒷자리의 수부터 빼낸 수가 총 k개가 될 때까지 다시 빼준다.
    while (s.size() > result_size) { 
        s.pop();
    }
    
    while(!s.empty()){ 
        answer += to_string(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end()); // 스택의 top부터 꺼냈으므로 순서를 뒤집어줘야 한다.
    
    return answer;
}
