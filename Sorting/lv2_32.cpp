/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42747 (프로그래머스 Level 2)

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index이다.
한 과학자의 각 논문의 인용 횟수를 담은 배열이 주어질 때, 이 과학자의 H-Index를 구하는 문제.

구현은 결론부터 말하자면 주어진 배열을 내림차순한 뒤 0번째 원소부터 탐색하며 배열의 i번째 원소값이 i보다 작거나 같을 때의 i를 리턴하면 된다.
이 코드가 성립하는 이유는 다음과 같다.
배열을 내림차순으로 정렬하면, 각 논문의 인용 횟수에 따라 내림차순으로 정렬된다.
따라서 i번째 논문보다 인용이 많이 된 논문의 개수는 0번째 논문부터 (i - 1)번째 논문까지 총 i개가 된다.
이때 만약 i번째 논문의 인용 횟수(citatioons[i])가 i보다 크다면, 0번째부터 i번째까지 최소 i + 1개의 논문은 i번 이상 인용됐다는 걸 보장할 수 있다.
여기서 H-Index는 주어진 조건을 만족하는 최댓값을 찾아야 하므로 탐색을 계속 진행한다.
만약 i번째 논문의 인용 횟수가 i보다 작거나 같은 i를 찾는다면, i번 보다 인용이 많이 된 논문의 개수는 딱 i개(citatioons[i] < i인 경우) 혹은 i + (인용 횟수가 i번인 논문의 개수)개(citatioons[i] == i인 경우)가 되므로 이때의 i가 조건을 만족하는 최댓값이 된다. 
여기서 탐색을 더 진행한다면 i값은 계속 커지므로 i번보다 인용이 많이 된 논문의 개수가 갈수록 적어져서 더이상 h번 이상 인용된 논문이 h편 이상이어야 한다는 조건을 만족할 수 없다.
테스트 케이스를 모두 통과하려면 몇 가지 예외 처리도 필요한데
[12, 14] 같이 배열의 길이보다 H-Index의 값이 큰 경우가 있다.
이 경우에는 H-Index의 값이 무조건 배열의 길이라는 것을 알면 쉽게 처리해줄 수 있다.

시간복잡도는 O(nlog n)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size(); // 예외 처리 - 밑에 if문에 걸리지 않는 경우 H-Index의 값은 배열의 길이가 된다.
    
    sort(citations.begin(), citations.end(), greater<int> ());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] <= i) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
