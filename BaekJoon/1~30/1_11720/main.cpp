// N개의 숫자가 공백 없이 쓰여 있다. 이 숫자를 모두 합해 출력하는 프로그램을 작성하시오.
// 1번째 줄에 숫자의 개수 N(1<= N <= 100), 2번째 줄에 숫자 N개가 공백 없이 주어진다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int N;
    string str;
    int sum = 0;

    cin >> N;
    cin >> str;

    for(int i = 0; i < N; i++) {
        sum += str[i] - '0';
    }

    cout << sum << "\n";

    return 0;
}