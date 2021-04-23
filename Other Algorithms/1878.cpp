/*
문제 출처 : 프로그래머스 - 나머지 한 점 (https://programmers.co.kr/learn/courses/18/lessons/1878)

직사각형의 세 점의 좌표가 주어졌을 때 나머지 하나의 좌표를 구하는 문제.
직사각형의 경우 x, y 각각 똑같은 좌표가 두 번씩 등장해야 만들어진다. 따라서 각각 3개의 입력값 x, y중 혼자 한 번만 등장한 x, y값이 정답이 된다.

다음처럼 단순 조건문을 이용해서 풀어도 되고 C++의 map을 이용해서 풀어도 된다.
비트연산자 XOR을 이용하면 
x = v[0][0]^v[1][0]^v[2][0];
y = v[0][1]^v[1][1]^v[2][1];
이렇게 더 간결한 코드로 풀 수도 있다.

시간복잡도는 O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;

    int x, y;
    
    if (v[0][0] != v[1][0]) {
        if (v[1][0] == v[2][0])
            x = v[0][0];
        else
            x = v[1][0];
    }
    else
        x = v[2][0];
    
    if (v[0][1] != v[1][1]) {
        if (v[1][1] == v[2][1])
            y = v[0][1];
        else
            y = v[1][1];
    }
    else
        y = v[2][1];
    
    ans.push_back(x);
    ans.push_back(y);
    
    return ans;
}
