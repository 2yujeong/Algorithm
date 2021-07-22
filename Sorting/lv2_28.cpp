/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42746 (프로그래머스 Level 2)

0 또는 양의 정수가 주어졌을 때, 정수들을 이어 붙여 만들 수 있는 가장 큰 수를 리턴하는 문제.

처음엔 정수들을 각 자리수별로 쪼개서 차례로 비교하는 방식으로 비교 함수를 작성했는데 코드가 너무 복잡하게 나왔다.
다른 풀이들을 참고하여 정수를 string으로 변환 후 이 문자열들을 서로 비교하여 정렬하는 비교 함수를 작성하였다. 
비교 함수에 매개변수로 두 문자열이 주어지면, 두 문자열 중 어느 문자열을 앞 순서에 위치시켰을 때 더 큰 문자열, 즉 이어붙였을 때 더 큰 정수가 만들어지는 지를 판별하고 판별된 순서를 리턴한다.

시간복잡도는 O(nlog n), n은 numbers 배열의 크기
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int n : numbers) {
        v.push_back(to_string(n));
    }
    
    sort(v.begin(), v.end(), comp);
    
    int val = 0;
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
        val += stoi(v[i]);
    }
    
    if (val == 0)
        return "0";
    
    return answer;
}
