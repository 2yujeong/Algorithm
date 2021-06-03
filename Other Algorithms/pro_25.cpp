/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12935 (프로그래머스 Level 1)

간단하지만 vector와 iterator 관련 함수들의 활용을 정리하기 좋은 문제였다.
처음에는 for문으로 직접 vector의 각 인덱스에 접근하며 탐색했는데 min_element(), find(), erase()와 같은 함수들을 사용하면 더 간단하게 구현할 수 있다.

참고 : iterator는 컨테이너에 저장된 원소를 순회하면서 접근하는 방법을 제공하는 반복자이다.
반복자는 * 연산자를 사용하여 컨테이너 내부의 원소를 가리키고 접근할 수 있으며, ++, !=, == 등의 이항연산자를 사용하여 다음 원소로 이동하거나 컨테이너의 모든 원소를 순회할 수 있다.

시간복잡도는 O(n)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1) {
        answer.push_back(-1);
        
        return answer;
    }
    
    arr.erase(min_element(arr.begin(), arr.end()));
    // min_element() : arr 배열에서 최소값인 원소의 위치를 반환한다.
    // arase() : 주어진 위치의 원소를 제거하고 그 뒤에 위치해있던 원소들을 한 칸씩 앞으로 당겨온다. -> O(n)
    
    return arr;
}
