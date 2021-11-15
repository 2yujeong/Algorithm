/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/87390 (프로그래머스 Level 2)

다음과 같은 과정을 거쳐서 1차원 배열을 만들고자 한다.
 1. n행 n열 크기의 비어있는 2차원 배열을 만든다.
 2. i = 1, 2, 3, ..., n에 대해, 1행 1열부터 i행 i열까지의 영역 내의 모든 빈 칸을 숫자 i로 채운다.
 3. 1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만든다.
 4. 새로운 1차원 배열을 arr이라 할 때, arr[left]부터 arr[right]까지의 데이터만 남기고 나머지는 지운다.
n, left, right가 주어질 떄, 주어진 과정대로 만들어진 1차원 배열을 리턴하는 문제.

n의 범위가 크기 때문에 1부터 n^2까지의 배열 전체를 구현하여 answer에 넣는 방식은 시간 초과가 난다.
규칙을 찾아 left부터 right까지의 값만 구해서 answer에 집어넣어야 한다.
left와 right를 n으로 나눈 값과 나눴을 떄의 나머지 값을 이용하여 규칙을 찾을 수 있었는데,
n개의 데이터마다 구간을 나눠서 이중 for문을 이용한 방식으로 구현하였다. 

테스트 케이스를 모두 통과하고 다른 사람의 풀이를 찾아보니 규칙만 찾으면 더 간단한 코드로 구현할 수 있었다.
left부터 right까지의 i에 대해
answer.push_back(max(i / n, i % n) + 1); 와 같이 구현해주면 한 줄의 코드로 구현해낼 수 있다.
시간복잡도는 변함 없지만 훨씬 빠르고 심플한 코드로 문제를 풀 수 있다.

시간복잡도는 O(right - left)
*/

#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left / n; i <= right / n; i++) {
        long long start = 0, end = n;
        
        if (i == left / n) 
            start = left % n;
        if (i == right / n)
            end = right % n + 1;
        
        for ( ; start < end; start++) {
            if (start < i)
                answer.push_back(i + 1);
            else
                answer.push_back(start + 1);
        }
    }
    
    return answer;
}
