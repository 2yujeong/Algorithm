/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/62048 (프로그래머스 Level 2)

W X H 크기의 직사각형을 1 X 1크기의 격자칸으로 나누고 대각선을 긋는다.
대각선이 지나가는 자리의 정사각형을 제외한 나머지 정사각형의 개수를 구하는 문제.

문제의 예시에서 주어진 그림을 보면 대각선이 지나가는 칸과 관련하여 최대공약수와 관련한 패턴이 존재한다는 걸 알 수 있다.
W와 H의 최대공약수를 gcd라고 하면, 가로가 W / gcd이고 세로가 H / gcd인 직사각형 패턴이 대각선을 따라 gcd개 존재한다.
하나의 패턴을 기준으로 대각선을 그었을 때 제외되는 정사각형을 보면, 해당 패턴의 가로 길이 + 세로길이 - 1만
큼의 정사각형이 제외된다는 걸 이용하면 문제를 풀 수 있다.
gcd를 구할 때 이용한 유클리드 알고리즘에 관한 설명은 https://github.com/2yujeong/Algorithm/commit/125dd7954c8b1cbf3d031bb588c39f6f63b35693 참조

시간복잡도는 유클리드 알고리즘을 이용하므로 O(log (min(W, H)))
*/

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    int n = gcd(w, h);
    long long pattern = (w / n + h / n) - 1; // 특정 패턴이 gcd만큼 반복되는 형태이므로 하나의 패턴에서 대각선을 그림으로써 제외되는 정사각형의 수를 계산
    answer = (long) w * h - pattern * n; // pattern * n = 하나의 패턴에서 제외되는 정사각형의 수 X gcd = 전체 직사각형에서 제외되는 정사각형의 수
    
    return answer;
}
