/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/42890 (프로그래머스 Level 2)

학생들의 인적사항 릴레이션이 주어질 때 후보키의 최대 개수를 구하는 문제.
후보키는 관계 DB에서 릴레이션의 튜플을 유일하게 식별할 수 있으며 다음 두 성질을 만족하는 속성 또는 속성의 집합을 의미한다.
- 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
- 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 
즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.

주어진 릴레이션의 컬럼 개수가 n이면, 1부터 n까지의 길이의 모든 컬럼 간의 조합을 DFS를 이용하여 구한다.
combination 배열에 모든 조합을 저장하고 각 조합 별로 유일성과 최소성을 만족하는 지 판별하여 풀었다.
유일성의 경우 모든 튜플에 대해 서로 중복되는 컬럼 값이 없는 지 map을 이용하여 판별한다.
최소성은 말 그대로 조합 내 모든 속성들이 튜플을 식별하는 데 있어서 유의미해야 하기 때문에
이미 유일성과 최소성을 만족해서 후보키가 된 컬럼 조합에 +@로 다른 컬럼이 추가된 조합은 최소성을 만족시키지 못한다.
+@로 추가된 그 컬럼이 튜플을 식별하는 데 있어서 유의미하지 않기 때문이다.
따라서 combination 배열을 원소의 길이를 기준으로 정렬 조합 내 컬럼의 개수가 작은 조합부터 유일성 판별을 시작하도록 하고
유일성을 만족하여 후보키가 됐다면, 아직 판별되지 않은 뒤의 조합을 중 후보키가 된 조합을 포함하는 조합을 찾아서 걸러내면 자동으로 최소성도 판별된다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> combination;
string temp;

// 조합 찾기
void comb(int value, int level, int n) {
	if (level == n)
		return;

	for (int i = value; i < n; i++) {
		temp[level] = i + '0';
		combination.push_back(temp.substr(0, level + 1));
		comb(i + 1, level + 1, n);
	}
}

bool comp(string a, string b) {
	return a.length() < b.length();
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int cnt = 0;

	temp.resize(relation[0].size());
	comb(0, 0, relation[0].size());
	vector<int> check(combination.size(), 0); // 이미 후보키로 판별된 조합을 포함하는 조합들, 즉 최소성을 만족시키지 못하는 조합들의 combination 배열에서의 인덱스를 표시한다.

	sort(combination.begin(), combination.end(), comp); 
    // 조합 A가 후보키이면, A 조합을 포함하는 조합 B는 최소성을 만족시키지 못한다. 
    // -> A를 먼저 구하고 A를 포함하는 더 큰 조합들을 체크함으로써 최소성을 만족하시키지 못하는 조합들을 거르기 위해
    // 조합에 포함된 튜플의 수를 기준으로 오름차순 정렬한다.

	for (string col : combination) {
		if (check[cnt] == 1) { // 앞서 이미 후보키로 판별된 조합을 포함하고 있으면, 후보키 판별 과정을 거쳐봤자 어차피 최소성을 만족시키지 못해 탈락하므로 넘어간다.
			cnt++;
            continue;
        }

		cnt++;
		map<string, int> m; // 유일성 판별을 위한 map

		for (int i = 0; i < relation.size(); i++) {
			string s = "";
			for (int j = 0; j < col.size(); j++) {
				s += relation[i][col[j] - '0'];
			}

			if (m.find(s) != m.end()) // 중복되는 튜플이 있다면 유일성을 만족시키지 못한다.
				break;
            
			m[s]++;

			if (i == relation.size() - 1) { // 유일성까지 만족시킨 경우
				answer++;

                // 최소성 판별을 위해 후보키로 판별된 현재 조합을 포함하는 모든 조합들을 체크한다.
				for (int k = cnt; k < combination.size(); k++) {
					int idx = 0;
					for (int l = 0; l < combination[k].length(); l++) {
						if (combination[k][l] == col[idx]) {
							if (idx == col.size() - 1) { 
								check[k] = 1;
								break;
							}

							idx++;
						}
					}
				}
			}
		}
	}

	return answer;
}
