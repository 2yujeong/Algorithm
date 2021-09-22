/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17683 (프로그래머스 Level 2)

방금극곡 서비스를 이용하여 네오가 찾으려는 음악의 제목을 구하는 문제.
 - 방금그곡 서비스에서는 음악 제목, 재생이 시작되고 끝난 시각, 악보를 제공한다.
 - 네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
 - 각 음은 1분에 1개씩 재생된다. 
 - 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다. 
 - 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
 - 음악이 00:00를 넘겨서까지 재생되는 일은 없다.
 - 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 
 - 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
 - 조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.

처음에는 투포인터를 이용하여 풀었더니 일부 테스트케이스를 통과하지 못했다.
'음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.' 등의 조건을 보고 문제가 잘 이해가 가지 않았는데
단순히 재생 시간 만큼 악보의 음들을 이어붙인 문자열과 m을 비교하면 되는 문제였다.
예를 들어 악보가 "ABCD"인 곡의 재생시간이 7초였다면 "ABCDABC"라는 문자열을 생성하고
생성한 문자열에 주어진 m이 포함되어 있는지를 문자열 매칭 알고리즘을 통해 판별하면 된다.
문자열 검색 알고리즘은 KMP, Boyer-Moore 알고리즘 등이 있지만
이 문제는 단순히 브루트포스로 비교해도 시간복잡도를 통과할 수 있다.

시간복잡도는 브루트포스로 문자열을 검색하는 과정이 O(mn)으로 n은 악보의 길이를 의미한다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    pair<int, string> p = {-1, "(None)"};
    
    for (string s : musicinfos) {
        int start = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        int end = stoi(s.substr(6, 2)) * 60 + stoi(s.substr(9, 2));
        int time = end - start;
        
        string title = "";
        string str = "";
        s = s.substr(12);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ',') {
                str = s.substr(i + 1);
                break;
            }
            else
                title += s[i];
        }
        
        s = "";
        for (int i = 0, j = time; j--; i++) {
            if (i == str.length())
                i = 0;
            
            s += str[i];
            
            if (i != str.length() - 1 && str[i + 1] == '#') {
                i++;
                s += str[i];
            }
        }
            
        for (int i = 0; i <= (int)(s.length() - m.length()); i++) {
            if (s[i] == m[0]) {
                for (int j = 1; j < m.length(); j++) {
                    if (m[j] != s[i + j])
                        break;
                    
                    if (j == m.length() - 1 && time > p.first) {
                        if (s[(j + i + 1) % s.length()] != '#')
                            p = {time, title};
                    }
                }
            }
            
            if (p.second == title)
                break;
        }
    }
    
    return answer = p.second;
}
