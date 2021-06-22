/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42577 (프로그래머스 Level 2)

전화번호부에 적힌 전화번호 중, 한 번호의 전체가 다른 번호의 접두어인 경우가 있으면 false, 없으면 true를 리턴하는 문제.

시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(string a, string b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    
    sort(phone_book.begin(), phone_book.end(), comp); // O(nlog n)
    
    for (string s : phone_book) { // O(n)
        string temp = "";
        for (int i = 0; i < s.length(); i++) { // O(1)
            temp += s[i];
            if (m.find(temp) != m.end()) // O(log n)
                return answer = false;
        }
        
        m[s] = 1; // O(log n)
    }
    
    return answer;
}
