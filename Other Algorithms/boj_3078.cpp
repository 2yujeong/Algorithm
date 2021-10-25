/*
문제 출처 : https://www.acmicpc.net/problem/3078 (백준 온라인 저지)

좋은 친구란 등수의 차이가 K보다 작거나 같으면서 이름의 길이가 같은 친구를 의미한다.
N명 학생들의 이름이 성적순으로 주어졌을 때, 좋은 친구가 몇 쌍이나 있는지 구하는 문제.

Map과 큐를 이용하여 슬라이딩 윈도우 방식으로 풀었다.
K + 1명의 학생에 대해 이름의 길이가 key인 학생의 수를 value로 하는 map을 생성하고
각 이름의 길이를 입력 받은 성적순대로 큐에 넣는다. 
Map과 큐에 저장된 학생의 수가 K + 1명을 초과할 때마다 큐의 맨 앞에 있는 이름의 길이를 map에서 찾아 value 값을 -1 해주고 큐에서 pop해준다.
입력 받은 i번째 이름의 길이가 m이라면, map에서 key 값이 m인 원소의 value 값이 i번째 학생과의 등수 차이가 K 이하이며 이름의 길이가 m으로 같은 학생의 수가 된다.

시간복잡도는 map의 find가 O(log m)이므로 입력 받은 이름의 최대 길이가 m이라고 하면 O(nlog m)
*/

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	map<int, int> m;
	long long result = 0;

	for (int i = 0; i < n; i++) {
		string name = "";
		cin >> name;

		if (i > k) {
			m[q.front()]--;
			q.pop();
		}

		q.push(name.length());

		if (m.find(name.length()) != m.end())
			result += m[name.length()];

		m[name.length()]++;
	}

	cout << result;

	return 0;
}
