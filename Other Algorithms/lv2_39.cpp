/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42885 (프로그래머스 Level 2)

무게 제한이 있으며 한 번에 최대 2명씩 탈 수 있는 구명보트로 사람들을 구출하려고 한다.
사람들의 몸무게가 담긴 people 배열이 주어지고 구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 할 때
필요한 구명보트의 개수의 최솟값을 리턴하는 문제.

우선 people 배열을 오름차순으로 정렬한다.
가장 몸무게가 많이 나가는 사람부터 구명보트에 태운다고 하면, 같이 태울 사람으로 가장 몸무게가 적은 사람을 고려한다.
가장 적게 나가는 사람이 같이 탈 수 없으면 많이 나가는 사람은 혼자 탈 수 밖에 없기 때문이다.
따라서 people 배열에 담긴 몸무게의 최댓값 + 최솟값이 limit 이내면 그 둘을 같이 태우고
limit를 넘으면 많이 나가는 사람만 혼자 태운다.

시간복잡도는 STL sort 때문에 O(nlog n)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int idx = 0;
    while (people.size() > idx) {
        if (people[idx] + people.back() <= limit)
            idx++;
        answer++;
        people.pop_back();
    }
    
    return answer;
}
