/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42862 (프로그래머스 Level 1)

체육복을 도난당한 학생들의 번호가 담긴 lost 배열, 여분 체육복을 한 벌 더 가지고 있는 학생들의 번호가 담긴 reserve 배열이 주어진다.
i번 학생은 i - 1번 학생 또는 i + 1번 학생에게만 체육복을 빌릴 수 있다고 할 때, 체육복을 입을 수 있는 학생 수의 최대값을 구하는 문제.

'여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.'
위와 같은 제한사항이 존재해서 계속 일부 테스트를 통과하지 못했다.
처음에는 O(lost.size())로 한 번에 해결하고자 lost 배열을 순차적으로 탐색하는 동시에 앞뒤로 여분 체육복을 가진 학생을 탐색했는데, 이렇게 구현할 경우 여벌 체육복이 있지만 도난 당한 학생이 lost 배열에서 자신보다 앞에 등장하는 학생에게 자신의 체육복을 빌려주는 경우가 발생할 수 있다.
따라서 체육복을 도난당한 경우도 lost 배열을 이용하여 clothes 배열에 먼저 다 반영해주고, 그 후 n개의 clothes 배열 원소를 앞에서부터 탐색한다.

시간복잡도는 전체 학생 수가 n일 때 O(n)
*/

#include <string>
#include <vector>

using namespace std;

int clothes[32]; // 학생들의 번호별로 여분 체육복의 수를 저장

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    for (int num : reserve) {
        clothes[num]++; // 여분 체육복 수가 1
    }
    
    for (int num : lost) {
        clothes[num]--; // 여분 체육복 수 1 감소 
    }
    
    for (int i = 1; i <= n; i++) {
        if (clothes[i] == -1) { // 자신이 입을 체육복도 없는 경우
            if (clothes[i - 1] > 0)
                clothes[i - 1]--;
            else if (clothes[i + 1] > 0)
                clothes[i + 1]--;
            else
                answer--;
        }
    }
    
    return answer;
}
