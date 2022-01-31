/*
문제 출처 : https://www.acmicpc.net/problem/10799 (백준 온라인 저지)

여러 개의 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 절단하려고 한다.
레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있다.
 - 레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘()’으로 표현된다. 모든 ‘()’는 반드시 레이저를 표현한다.
 - 쇠막대기의 왼쪽 끝은 여는 괄호 ‘(’로, 오른쪽 끝은 닫힌 괄호 ‘)’로 표현된다. 
쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 주어졌을 때, 잘려진 쇠막대기 조각의 총 개수를 구하는 문제.

변수 sticks는 현재 레이저에 의해 절단될 수 있는 쇠막대기의 개수를 의미한다.
'('가 한 번 등장할 때마다 sticks를 하나 늘려주고 ')'가 등장하면 sticks를 하나 줄여준다.
이때 '(' 다음에 바로 ')'가 오는 경우는 쇠막대기가 아닌 레이저를 의미하므로, 레이저에 의해 절단됨으로써 추가된 쇠막대기의 개수를 총합 sum에 추가해준다.
레이저가 발사되면 sticks개의 각 쇠막대기들이 둘로 나눠지므로 총합에 sticks만큼 더해주면 된다.

시간복잡도는 O(n)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sticks = 0;
	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				sum += sticks;
				i++;
				continue;
			}
			sticks++;
			sum++;
			continue;
		}
		sticks--;
	}

	cout << sum;

	return 0;
}
