/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12915 (프로그래머스 Level 1)

문자열로 구성된 리스트 strings와 정수 n이 주어졌을 때, 각 문자열을 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하는 문제.
인덱스 n의 문자가 같은 문자열이 여럿일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치하도록 한다.
STL sort()에 사용될 비교함수(comp)를 따로 정의하여 풀었다.

시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool comp(string a, string b) {
    return a[idx] < b[idx] || (a[idx] == b[idx] && a < b);
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    
    return strings;
}
