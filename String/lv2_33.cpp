/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12981 (프로그래머스 Level 2)

n명의 사람들이 진행한 끝말잇기에 사용된 단어들이 순서대로 words 배열에 담겨서 입력으로 주어진다.
가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지 구하는 문제.
주어진 단어들로 탈락자가 생기지 않는다면 (0, 0)을 리턴한다.

words 배열의 단어들을 앞에서부터 순차적으로 탐색하며 탈락인지 아닌지를 판별한다.
key가 단어, value가 단어의 등장 횟수인 map을 이용하여 중복되는 단어인지 판별하고
단어의 맨 뒷글자를 end 변수에 담아 다음 단어의 첫 글자와 이어지는지 비교해준다.
탐색이 끝나면 카운트 값을 이용하여 탈락자 발생 여부와 탈락자의 번호, 탈락 차례를 계산하고 answer에 담는다.

시간복잡도는 map의 탐색이 O(log n)이므로 log 1부터 log n까지의 합이 된다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    map<string, int> m;
    int cnt = 1;
    char end = words[0][0];
    
    for (string s : words) {
        if (s[0] == end) {
            if (m.find(s) != m.end())
                break;
            else {
                cnt++;
                end = s[s.length() - 1];
                m[s]++;
            }
        }
        else
            break;
    }
    
    if (cnt == words.size() + 1) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        if (cnt % n == 0) {
            answer.push_back(n);
            answer.push_back(cnt / n);
        }
        else {
            answer.push_back(cnt % n);
            answer.push_back(cnt / n + 1);
        }
    }

    return answer;
}
