/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12941 (프로그래머스 Level 2)

자연수로 이루어진 서로 길이가 같은 배열 A, B가 있다.
A, B에서 각각 하나씩 수를 뽑아 두 수를 서로 곱하는 과정을 배열의 길이만큼 반복한다.
곱한 값들을 모두 더한 누적합을 구한다고 할 때, 누적합의 최솟값을 리턴하는 문제.

곱하기 연산의 특성 상 큰 수끼리 곱할수록 그 값이 배로 커지기 때문에 큰 수일수록 작은 수와 곱하는 게 최소 누적합을 만들기 적합하다.
따라서 배열 A는 오름차순으로, B는 내림차순으로 정렬한 후 앞 인덱스부터 차례로 곱해서 더해주면 최소 누적합을 구할 수 있다.

시간복잡도는 O(nlog n)
*/

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }

    return answer;
}
