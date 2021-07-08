/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/64065 (프로그래머스 Level 2)

원소의 개수가 n개이고, 중복되는 원소가 없는 튜플(a1, a2, a3, ..., an)이 있을 때, 이 튜플을 n개의 집합으로 표현하는 문자열 s가 입력으로 주어진다.
s가 표현하는 튜플을 배열에 담아 리턴하는 문제.

튜플은 원소 간의 순서가 존재하는데, 입출력 예를 보면 많이 등장한 수일 수록 튜플의 앞 순서에 위치한다는 걸 알 수 있다.
따라서 입력에서 총 n번 등장한 수는 (튜플의 전체 크기 - n) 번째 인덱스에 위치하므로
등장한 숫자들을 key, 각 숫자들의 등장 횟수를 value로 저장하는 map을 이용하여 풀 수 있다.

시간복잡도는 O(n), n은 문자열 s의 길이
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m; // (원소 값, 등장 횟수)를 저장하기 위한 map
    int size = -1; // 튜플의 원소의 개수를 알기 위한 변수
    
    // 문자열을 수로 변환하기 위한 변수
    string temp;
    int flag = 0;
    
    for (char c : s) {
        if (c == '{' || c == '}' || c == ',') {
            if (c == '{') // '{'의 등장 횟수 - 1이 튜플의 크기가 된다.
                size++;
            if (flag == 1) { // 바로 앞 순서의 문자까지가 숫자였을 경우
                flag = 0; // 현재 순서의 문자는 숫자가 아니므로 0으로 reset
                m[stoi(temp)]++; // string으로 저장해놓은 숫자들을 int로 변환하고 해당 값들의 등장 횟수를 +1 해준다.
                temp = ""; // 다음 숫자를 받기 위해 temp 초기화
            }
        } 
        else { 
            if (flag == 0) 
                flag = 1;
            
            temp += c; // 숫자가 십의 자리 이상의 수인 경우 한 자리씩 변환하면 안 되므로 temp에 저장해놨다가 한꺼번에 변환
        }
    }
    
    answer.resize(size);
    
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        answer[size - it->second] = it->first; 
        // 많이 등장한 수일 수록 튜플의 앞 순서에 위치
        // => 총 n번 등장한 수는 (튜플의 전체 크기 - n) 번째 인덱스에 위치한다.
    }
    
    return answer;
}
