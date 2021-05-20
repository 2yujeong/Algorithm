/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/68644 (프로그래머스 Level 1)

정수 배열 numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return하는 문제.

이중 for문을 이용하면 더 간단하게 풀 수 있지만 재귀함수에 익숙해지기 위해 조합 알고리즘을 구현하여 풀었다.
결과 배열은 중복을 제거해야 하므로 <algorithm>의 sort(), unique(), erase()를 이용하였다.
+ 중복 제거는 자료구조 set을 이용해서 구현할 수도 있다.

참고 : vector 내 중복 제거
1. unique() 함수는 서로 인접한 두 수끼리만 비교하여 중복을 탐지하므로 먼저 sort()를 이용한 정렬이 필요하다.
2. unique() 함수는 중복된 값들을 배열의 맨 뒤쪽으로 넘기는데, 함수 호출이 끝나면 이 넘겨진 중복값들 중 첫 번째 중복값의 iterator를 반환한다.
3. vector.erase() 함수와 unique() 호출 결과 반환된 iterator를 이용하여 vector에서 중복값들을 제거한다.

시간복잡도는 조합 알고리즘의 경우 지수 시간이 걸리지만 이중 for문을 이용해서 구현하면 O(n^2)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
vector<int> answer;

void comb(int val, int level, vector<int>& numbers) {
    if (level == 2) {
        answer.push_back(sum);
        
        return;
    }
    
    for (int i = val; i < numbers.size(); i++) {
        sum += numbers[i];
        comb(i + 1, level + 1, numbers);
        sum -= numbers[i];
    }
}

vector<int> solution(vector<int> numbers) {
    comb(0, 0, numbers);
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}
