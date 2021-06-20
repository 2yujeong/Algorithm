/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42860 (프로그래머스 Level 2)

조이스틱을 조작하여 주어진 이름과 똑같은 문자열을 만들어야 한다.
주어진 이름이 n글자면 'A'로만 구성된 n글자의 문자열이 초기에 주어진다.
조이스틱을 위 / 아래로 움직이면 각각 다음 / 이전 알파벳으로 바꿀 수 있고 왼쪽 / 오른쪽으로 움직이면 커서가 왼쪽 / 오른쪽으로 이동한다.
주어진 이름을 완성하기 위한 조이스틱 조작 횟수의 최솟값을 리턴하는 문제.

현재 커서의 위치를 기준으로 가장 가까운 거리의 알파벳 조작이 필요한 글자를 찾고 주어진 이름에 맞게 알파벳을 조작하도록 Greedy로 구현하였다.

시간복잡도는 알파벳 조작이 O(1), 커서 이동이 O(n)이므로 O(n)
*/

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i = 0, flag = 0;
    
    while (1) {
        if (name[i] != 'A') { // 알파벳을 주어진 이름과 맞추기 위해 조이스틱을 조작해야 하는 경우
            if (name[i] <= 'N')
                answer += name[i] - 'A'; // 조이스틱을 위로 조작하는 횟수
            else
                answer += 26 - (name[i] - 'A'); // 조이스틱을 아래로 조작하는 횟수
            
            name[i] = 'A';
        }
        
        // Greedy => 현재 커서의 위치를 기준으로 오른쪽 또는 왼쪽으로 커서를 이동시키며 가장 가까운 거리의 알파벳 조작이 필요한 글자를 찾는다.
        int j = i, k = i, cnt = 0; 
        while (name[j] == 'A' && name[k] == 'A') {
            j++; // 오른쪽 방향으로 진행하며 맞지 않는 글자를 찾는다.
            if (j == name.length())
                j= 0;
            
            k--; // 왼쪽 방향으로 진행하며 맞지 않는 글자를 찾는다.
            if (k == -1)
                k = name.length() - 1;
            
            cnt++;
            if (cnt == name.length())  // name[]을 모두 순회했음에도 고쳐야할 알파벳이 없으면 이름이 완성된 경우이므로 결과 리턴
                return answer;
        }
        
        if (name[j] != 'A') // 조작이 필요한 알파벳이 커서를 오른쪽으로 진행했을 때 더 가까이 있는 경우
            i = j;
        else // 커서를 왼쪽으로 진행했을 때 더 가까이 있는 경우
            i = k;
        answer += cnt;
    }
    
    return answer;
}
