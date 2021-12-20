/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/87377 (프로그래머스 Level 2)

Ax + By + C = 0으로 표현할 수 있는 n개의 직선이 주어질 때, 이 직선의 교점 중 정수 좌표에 별을 그리려고 한다.
별이 그려진 좌표계의 상태를 문자열로 나타낼 때, 별이 그려진 부분은 '*', 빈 공간(격자선이 교차하는 지점)은 '.'으로 표현한다.
이때 격자판은 무한히 넓으니 모든 별을 포함하는 최소한의 크기만 나타내면 된다.
직선 A, B, C에 대한 정보가 담긴 배열이 매개변수로 주어질 때, 모든 별을 포함하는 최소 사각형을 표현한 문자열을 리턴하는 문제.
[문제 참고 사항]
다음과 같은 두 직선에 대해
 Ax + By + E = 0
 Cx + Dy + F = 0
AD - BC = 0인 경우 두 직선 간의 교점은 존재하지 않으며
교점이 존재할 경우 그 좌표는 x = (BF - ED) / (AD - BC), y = (EC - AF) / (AD - BC)이다.

문제에서 주어진 두 직선의 교점을 구하는 식을 이용하여 구현해주면 된다.
이때 A, B, C의 범위가 -100,000 이상 100,000 이하인 정수이므로 
계산 과정에서 int형을 벗어나는 경우가 있기 때문에 자료형에 유의해서 풀어야 한다.
만약 계산 결과인 x에만 long long형을 적용한다면 BF, ED, AD, ... 등이 int형을 벗어나는 경우를 통과하지 못 하므로
모든 계산 과정에 long long형을 적용 시켜줘야 한다.
또한 처음에는 long double형을 이용하여 분자를 분모로 나눈 온전한 x, y를 구하고 그 x, y가 정수인지 판별하는 방식으로 구현했는데,
이럴 경우 부동소수점 오차 때문인지 모든 테스트케이스를 통과하지 못했다.
따라서 분자 값만 우선 x에 저장한 뒤, 앞서 구해둔 분모로 분자를 나눈 나머지가 0인지 아닌지로 정수 여부를 판별하고
정수인 경우에만 분자를 분모로 나눠 x, y를 구하는 방식으로 소수점이 발생하지 않도록 처리해주면 모든 테스트케이스를 통과할 수 있다.

시간복잡도는 우선 교점의 좌표를 구하는 과정이 O(n^2)이 걸린다.
교점을 나타내는 문자열을 생성하는 과정의 경우
직선이 n개일 때의 직선의 교점의 최대 개수가 n(n - 1) / 2이고 Red-Black Tree로 구현된 STL Set의 탐색 연산이 O(log n)이므로
교점의 좌표를 저장하는 stars set의 find() 연산이 O(2log n)이 된다.
문제에서 정답이 1,000 * 1,000 크기 이내에서 표현된다고 했으므로, 총 시간복잡도는 대략 O(n^2 + 2,000,000log n)이 된다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>
#define ll long long

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<ll, ll>> stars;
    ll max_x = LLONG_MIN, max_y = LLONG_MIN, min_x = LLONG_MAX, min_y = LLONG_MAX;
    
    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            ll denominator = 1LL * line[i][0] * line[j][1] - 1LL * line[i][1] * line[j][0]; // AD - BC
            if (denominator != 0) { // 교점이 존재하는 경우
                ll x = 1LL * line[i][1] * line[j][2] - 1LL * line[i][2] * line[j][1]; // BF - ED
                ll y = 1LL * line[i][2] * line[j][0] - 1LL * line[i][0] * line[j][2]; // EC - AF
                
                if (x % denominator == 0 && y % denominator == 0) { // 교점이 정수인 경우
                    x /= denominator;
                    y /= denominator;
                    
                    stars.insert({(ll)x, (ll)y});
                    
                    max_x = max(max_x, (ll)x);
                    max_y = max(max_y, (ll)y);
                    min_x = min(min_x, (ll)x);
                    min_y = min(min_y, (ll)y);
                }
            }
        }
    }
    
    for (ll i = max_y; i >= min_y; i--) {
        string result = "";
        for (ll j = min_x; j <= max_x; j++) {
            if (find(stars.begin(), stars.end(), make_pair(j, i)) != stars.end()) 
                result += "*";
            else
                result += ".";
        }
        answer.push_back(result);
    }
    
    return answer;
}
