/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17680 (프로그래머스 Level 2)

도시 이름을 저장하는 캐시를 DB에 적용하려고 한다.
이 캐시는 LRU 알고리즘을 사용한다고 할 때 주어진 도시 배열과 캐시 크기에 따른 실행시간 측정 프로그램을 작성하는 문제.
실행시간은 cache hit일 경우 1, cache miss일 경우 5이며 도시 이름은 대소문자를 구분하지 않는다.

캐시 vector를 정의하고 LRU 알고리즘을 직접 구현하여 풀었다.
캐시의 원소들과 차례로 비교하여 삽입될 위치를 찾고 그 위치에 삽입하기 위해 원소들을 한 칸씩 앞으로 옮기는 삽입정렬을 이용한다.
캐시의 크기가 0일 경우 무조건 cache miss이므로 예외처리를 해주고
캐시의 크기가 1인 경우에는 똑같은 도시 이름이 연속으로 들어올 때 cache hit가 발생하므로 따로 예외처리를 해주지 않는다.

시간복잡도는 O(nm), n은 cacheSize, m은 cities 배열의 크기
*/

#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if (cacheSize == 0) // 캐시 사이즈가 0인 경우 항상 miss
        return cities.size() * 5;
    
    vector<string> cache(cacheSize);
    
    for (string city : cities) {
        for (int i = 0; i < city.length(); i++) {
            city[i] = tolower(city[i]); // 대소문자를 구분하지 않으므로 모두 소문자로 치환 후 진행
        } 
        
        int hit = -1;
        for (int i = cacheSize - 1; i >= 0; i--) { // hit인지 miss인지 판별
            if (cache[i] == city) { // hit라면 hit가 발생한 위치 저장
                hit = i;
                break;
            }
        }
        
        if (hit == -1) { // cache miss
            for (int i = 1; i < cacheSize; i++) {
                cache[i - 1] = cache[i];
            }
            
            answer += 5;
        }
        else { // cache hit
            for (int i = hit + 1; i < cacheSize; i++) {
                cache[i - 1] = cache[i];
            }
            
            answer += 1;
        }
        
        cache[cacheSize - 1] = city;
    }
    
    return answer;
}
