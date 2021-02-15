/*
입력된 N개의 정수에 대해 음의 정수를 앞쪽에, 양의 정수를 뒷쪽에 위치하게 정렬하는 문제.
음의 정수와 양의 정수 내에서의 입력 순서는 바뀌면 안 되므로 이웃한 원소끼리 비교하여 앞 원소가 양수 뒤 원소가 음수면 서로 위치를 바꿔주는 식의 버블정렬 응용 문제이다.
쉬운 문제이므로 버블정렬이 아닌 2개의 vector를 이용하여 간단하게 풀었다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num > 0)
			a.push_back(num);
		else
			b.push_back(num);
	}


	for (int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	
	return 0;
}
