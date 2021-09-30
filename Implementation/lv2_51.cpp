/*
n진수 게임의 규칙은 다음과 같다. 
 1. n진수로 변환된 숫자를 0부터 시작해서 차례대로 말한다. n이 10이라면 첫 번째 사람은 0, 두 번째 사람은 1, … 열 번째 사람은 9를 말한다.
 2. 두 자리 수 이상의 숫자부터는 한 자리씩 끊어서 말한다. 즉 10의 경우 앞사람은 10의 첫 자리인 1, 뒷사람은 둘째 자리인 0을 말한다.
게임은 이진법에서 십육진법까지의 진법 중 하나로 진행되며 
게임에 참가하는 인원 m명 중 p번째 사람이 말해야 하는 숫자 t개를 차례로 문자열에 담아 리턴하는 문제. 

주어진 n에 따라 숫자 1부터 차례로 n진법으로 변환하고
변환된 수들은 문자열로 변환하여 차례로 num_arr에 저장한다.
num_arr을 이용하여 m명 중 p번째 사람이 말해야 하는 수 t개를 answer에 추가해주면 된다.
m명이서 진행하면서 한 사람에게 총 t번의 순서가 돌아오려면 턴이 최대 t번 돌아야 하기 때문에
n진법으로 변환하는 과정은 num_arr의 길이가 t * m이 될 때까지 진행한다.

시간복잡도는 O(tm)
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string num_arr = "0"; // 0부터 차례대로 n진수로 변환된 수들을 저장
    
    for (int i = 1; num_arr.length() <= t * m; i++) { 
    // m명이서 진행하면서 한 사람에게 총 t번의 순서가 돌아오려면 턴이 t번 돌아야 하므로 문자열의 길이는 t * m까지 구한다.
        int num = i;
        string temp = "";
        
        while (num != 0) { // n진수로 변환
            string remainder = to_string(num % n);
            switch (num % n) {
                case 10:
                    remainder = "A";
                    break;
                case 11:
                    remainder = "B";
                    break;
                case 12:
                    remainder = "C";
                    break;
                case 13:
                    remainder = "D";
                    break;
                case 14:
                    remainder = "E";
                    break;
                case 15:
                    remainder = "F";
            }
            
            temp = remainder + temp;
            num /= n;
        }
        
        num_arr += temp; // n진수로 변환된 num을 뒤에 추가
    }
    
    for (int i = p - 1; answer.length() < t; i += m) { // m명 중 p번째 순서인 사람이 말해야 하는 숫자들을 저장
        answer += num_arr[i];
    }
    
    return answer;
}
