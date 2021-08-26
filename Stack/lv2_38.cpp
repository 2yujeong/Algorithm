/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42584 (프로그래머스 Level 2)

초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 리턴하는 문제.

스택에 주식가격이 아닌 주식가격이 기록된 시점, 즉 prices 배열의 인덱스를 넣어줌으로써 풀었다.
스택의 top()의 시점의 주식가격이 현재시점(i)의 주식가격보다 크다면, top() 시점에서의 주식가격은 i초 뒤에 떨어진 게 된다. 
따라서 top() 시점을 기준으로 가격이 떨어지지 않은 기간은 i - top()이 되고, answer[top()]에 바로 그 값을 넣어주면 된다.
가격이 한 번 이상 떨어진 시점은 가격이 떨어지지 않은 기간이 이미 결정되었으므로 스택에서 빼주고
스택에 끝까지 남아있는 시점들은 해당 시점에서의 가격보다 떨어진 시점이 뒤에 없다는 뜻이므로 
각 시점으로부터 몇 초 뒤에 기록이 끝나는 지만 구하면 된다.

시간복잡도는 처음 for문이 O(2n), 두 번째 while문이 O(n)이므로 총 시간복잡도 O(n)
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer (prices.size());
    
    stack<int> s;
    
    for (int i = 0; i < prices.size(); i++) {
        // 자신보다 더 큰 가격이 앞에 등장했었다면(s.top() 시점에서의 값 > 현재 시점에서의 값) 
        // 그 가격(s.top() 시점에서의 가격)은 현재 시점을 기준으로 가격이 떨어진 게 된다.
        while (!s.empty() && prices[s.top()] > prices[i]) { 
            answer[s.top()] = i - s.top(); // s.top() 시점으로부터 i 시점까지 가격이 떨어지지 않았으므로 가격이 떨어지지 않은 기간은 i - s.top()
            s.pop();
        }
        
        s.push(i);
    }
    
    while (!s.empty()) {
        // 스택에 계속 남아있는 값들은 해당 시점에서의 가격이 끝까지 떨어지지 않았다는 의미이므로
        // prices 배열에서 자신보다 뒤에 있는 수가 몇 개인 지만 계산하면 된다.
        answer[s.top()] = prices.size() - s.top() - 1; 
        s.pop();
    }
    
    return answer;
}
