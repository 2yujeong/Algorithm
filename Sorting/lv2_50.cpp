/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/17686 (프로그래머스 Level 2)

파일명을 기준으로 정렬하는 문제.
파일명은 크게 HEAD, NUMBER, TAIL의 세 부분으로 구성된다.
정렬 기준은 다음과 같다. 
 1. 우선 HEAD 부분을 기준으로 사전 순으로 정렬한다. 이때, 문자열 비교 시 대소문자 구분을 하지 않는다.
 2. 파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬한다.
 3. 두 파일의 HEAD 부분과, NUMBER의 숫자도 같을 경우, 원래 입력에 주어진 순서를 유지한다. 

파일명의 HEAD, NUMBER와 해당 파일명이 매개변수 files 배열에서 몇 번째 원소인지 알기 위한 인덱스를 저장하는 name 클래스를 선언한다.
name 객체를 원소로 담는 names vector를 선언하고
files의 각각의 파일명을 파싱하여 HEAD, NUMBER로 나눈 뒤 인덱스 값과 함께 name 객체를 생성하여 names에 넣어준다.
STL Sort를 이용하여 names를 정렬하는데 문제에서 주어진 정렬 기준을 적용하기 위해 비교함수 comp를 따로 선언해줘야 한다.
이때 그냥 sort()를 사용하여 정렬하면 정렬 기준 3번을 만족하지 못한다.
HEAD와 NUMBER가 같을 때는 원래 입력에 주어진 순서를 유지해야 하는데 sort()는 stable 특성을 보장하지 않기 때문이다.
예를 들어 file012.zip과 file012.txt가 차례로 들어올 경우, 두 파일명의 HEAD와 NUMBER와 같으므로 앞서 들어온 file012.zip이 더 앞순서로 정렬되어야 한다.
하지만 sort()는 unstable sort이기 때문에 file012.zip이 먼저 올 지 file012.txt가 먼저 올 지 알 수 없는 것이다.
따라서 stable_sort()를 사용하여 stable한 특성을 보장하는 정렬을 수행해야 한다.

참고 : 중복된 값의 정렬에 대해, 입력 순서와 정렬 후 순서가 동일하게 유지되는 정렬 알고리즘을 stable한 정렬 알고리즘이라고 한다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class name {
    public:
    string head;
    int number;
    int idx;
    
    name(string a, int b, int c) {
        head = a;
        number = b;
        idx = c;
    }
};

bool comp(name a, name b) { // 주어진 조건에 따라 head, number를 기준으로 정렬하기 위한 비교 함수 정의
    // 비교 시 대소문자를 구분하지 않으므로 모두 소문자로 변환 후 비교
    string head_a = "", head_b = ""; 
    
    for (int i = 0; i < a.head.length(); i++) {
        head_a += tolower(a.head[i]);
    }
    
    for (int i = 0; i < b.head.length(); i++) {
        head_b += tolower(b.head[i]);
    }
    
    return (head_a < head_b) // HEAD 기준 사전 순으로 정렬
        || (head_a == head_b && a.number < b.number); // HEAD가 같으면 NUMBER의 숫자 순으로 정렬
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<name> names;
    
    for (int i = 0; i < files.size(); i++) {
        string head  = "";
        string num = "";
        
        int j = 0;
        for (; j < files[i].length(); j++) { // 파일명에서 HEAD 분류
            if (files[i][j] >= '0' && files[i][j] <= '9')
                break;
           
            head += files[i][j];
        }
        
        for (int k = 0; k < 5, j < files[i].length(); k++, j++) { // 파일명에서 NUMBER 분류
            if (files[i][j] < '0' || files[i][j] > '9')
                break;
            
            num += files[i][j];
        }
        
        name temp = name(head, stoi(num), i); // HEAD, NUMBER, Index를 이용하여 name 객체 생성
        names.push_back(temp);
    }
    
    stable_sort(names.begin(), names.end(), comp); // 위에서 정의한 비교 함수를 이용하여 정렬
    
    for (name n : names) {
        // 정렬된 name 객체들의 인덱스를 이용하여 files에 들어있는 tail까지 포함된 전체 파일명을 앞서 정렬한 순서대로 answer에 저장
        answer.push_back(files[n.idx]); 
    }
    
    return answer;
}
