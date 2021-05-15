/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/72410 (프로그래머스 Level 1)

새로 가입하는 유저들이 규칙에 맞지 않는 아이디를 입력했을 때, 입력된 아이디와 유사하면서 규칙에 맞는 아이디를 추천해주는 프로그램을 개발하는 문제.
string의 tolower(), substr() 등의 함수를 잘 활용하면 어렵지 않게 풀 수 있다.

시간복잡도는 입력 문자열의 길이인 O(n)
*/

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0; i < new_id.size(); i++) {
        // Step 1 - 모든 대문자를 대응되는 소문자로 치환
        if (new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] = tolower(new_id[i]);
        
        // Step 2 - 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
        else if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.' &&
                 (new_id[i] < '0' || (new_id[i] > '9' && new_id[i] < 'a') || new_id[i] > 'z'))
            continue;
        
        // Step 3 & 4
        if (new_id[i] == '.') { // 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
            for (int j = i + 1; j < new_id.size() && new_id[j] == '.'; j++) {
                i = j;
            }
            
            // 마침표(.)가 처음에 위치한다면 제거 &  마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
            if (answer.size() == 0 || answer.back() == '.' )
                continue;
        }
            
        answer += new_id[i];
    }
    
    // Step 4 - 마침표(.)가 끝에 위치한다면 제거
    if (answer.size() > 0 && answer.back() == '.')
        answer = answer.substr(0, answer.size() - 1);   
    
    // Step 5 - 빈 문자열이라면 "a"를 대입
    if (answer.size() == 0)
        answer = "a";
    
    // Step 6 - 길이가 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if (answer[14] == '.') // 제거 후 마침표(.)가 문자열의 맨끝에 위치한다면 마침표(.) 문자를 제거
            answer = answer.substr(0, 14);
    }
    
    // Step 7 - 길이가 2자 이하라면, 마지막 문자를 문자열의 길이가 3이 될 때까지 반복해서 끝에 붙이기
    else if (answer.size() <= 2) {
        while (answer.size() != 3) {
            answer += answer.back();
        }
    }
    
    return answer;
}
