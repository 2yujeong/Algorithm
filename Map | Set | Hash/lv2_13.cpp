/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17677 (프로그래머스 Level 2)

두 집합 A, B 사이의 자카드 유사도를 구하여 65536을 구하는 문제. 
자카드 유사도는 집합 A, B의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.
입력으로 들어오는 두 개의 집합은 문자열이며, 각각의 문자열을 두 글자씩 끊어서 다중집합의 원소로 만든다.
이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
대문자와 소문자의 차이는 무시한다.

MultiSet을 이용하는 해결 방식은 쉽게 떠올랐지만 구현이 까다로웠다.
구체적인 구현 방식은 먼저 집합 A의 문자열부터 조건에 맞게 끊은 후 모두 Set에 넣어준다. 
집합 B의 문자열도 알맞게 끊은 후 각 원소들에 대해 Set에 이미 존재하는 원소면 A와 교집합을 이루는 원소이므로 inter_size 변수 값을 증가시키고, 그렇지 않으면 교집합이 아닌 합집합에 포함시켜야 하므로 union_size 변수 값을 증가시킨다.
테스트 케이스 7, 9, 10, 11에서 계속 실패했는데, 나같은 경우는 교집합에 포함되지 않는 B의 원소를 Set에 넣어줬기 때문에 문제가 발생했다.
저렇게 구현하면 "AA"라는 원소가 A에는 존재하지 않고 B에만 두 개 이상 존재하는 경우 의도한 대로 동작하지 않는다.
(처음 등장하는 B의 원소 "AA"가 교집합에 포함되지 않으니 Set에 들어가면 두 번째 B의 원소 "AA"는 자신보다 앞서 들어간 B의 원소 "AA"와 교집합을 이루게 된다.)
따라서 교집합, 합집합 구현에 유의해야 한다.

시간복잡도는 MultiSet의 탐색(find() 연산)이 O(log n)이므로 O(mlog n) (m은 문자열2의 길이, n은 문자열1의 길이)
*/

#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int inter_size = 0, union_size = 0;
    
    multiset<string> s;
    
    // 소문자로 치환 -> 대문자, 소문자는 소문자로 변환해주며 그외 문자들은 변환되지 않고 그대로 남는다.
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for (int i = 0; i < str1.size() - 1; i++) { // 집합 A의 원소 처리
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
            s.insert(str1.substr(i, 2));
    }
    
    for (int i = 0; i < str2.size() - 1; i++) { // 집합 B의 원소 처리 
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
            multiset<string>::iterator it = s.find(str2.substr(i, 2));
            if (it != s.end()) {
                inter_size++;
                s.erase(it);
            }
            else // 테스트 케이스 7, 9, 10, 11 주의
                union_size++; 
            // 이때 B의 원소가 교집합에 포함되지 않는다고 원소를 set에 넣어주면 A에는 "AA"가 없고 B에는 "AA"가 두 개 존재하는 경우에도 이 "AA"를 교집합에 포함시켜 버린다. 
            // 따라서 set에 다시 넣어주면 안 되고 교집합에 포함되지 않는 B의 원소는 따로 빼줘야 한다. 
            // set을 따로 선언해서 거기에 넣거나 이렇게 그냥 union_size 변수를 이용해줘도 된다.
        }
    }
    
    union_size += inter_size + s.size(); // 교집합(inter_size) + 교집합에 포함되지 않은 A의 원소(s.size()) + 교집합에 포함되지 않은 B의 원소(위의 else에서 증가시켜준 union_size의 값)
    if (union_size == 0)
        return answer = 65536;
    
    float temp = (float) inter_size / union_size;
    answer = temp * 65536;
    
    return answer;
}
