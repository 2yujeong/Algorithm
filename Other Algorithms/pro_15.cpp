/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17681 (프로그래머스 Level 1)

비밀지도를 해독하여 '#' 또는 ' '(공백)으로 구성된 문자열을 return하는 문제. 해독법은 다음과 같다.
1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다.
3. 각각의 지도는 정수 배열로 암호화되어 있다.
4. 암호화된 배열의 각 원소는 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 십진수 값이다.

지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이며 모두 공백인 부분은 전체 지도에서도 공백이므로 비트마스킹 OR 연산을 이용할 수 있다.

시간복잡도의 경우 비트마스크 연산은 대부분 O(1)에 구현되지만 이 문제에서는 이중 for문이 사용되므로 O(n^2)이 걸린다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        v[i] = arr1[i] | arr2[i];
        
        cout << v[i] << endl;
        
        string s = "";
        for (int j = 0; j < n; j++, v[i] /= 2) {
            if (v[i] % 2 == 0)
                s = " " + s;
            else
                s = "#" + s;
        }
    
        answer.push_back(s);
    }

    return answer;
}
