/*
문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/82612 (프로그래머스 Level 1)

이용료가 price원인 놀이기구가 있다.
이 놀이기구는 n번째 탈 때마다 원래 이용료의 n배를 내야 한다.
놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지를 리턴하는 문제.

처음에는 단순히 for문을 이용하여 1부터 count까지의 수에 price에 곱한 값을 total에 계속 더해주었다.
이 경우 O(count)의 시간복잡도가 나오는데, 등차수열을 이용하면 더 간단하게 풀 수 있다.
입출력 예를 보면 3 + 6 + 9 + 12 = 30이 되는데 이는 (1 + 2 + 3 + 4) X 3과 같다.
따라서 등차수열을 이용하여 1부터 count 까지의 합을 구하고 그 값에 price를 곱해주면 더 빠르고 간단하게 풀 수 있다.

시간복잡도는 O(1)
*/

using namespace std;
#include <iostream>
long long solution(int price, int money, int count)
{
    long long total = (long long) (count + 1) * count / 2 * price;
    
    if (money - total < 0)
        return total - money;
    else
        return 0;
}
