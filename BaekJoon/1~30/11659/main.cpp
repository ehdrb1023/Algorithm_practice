// 수 N개가 주어졌을 때 i번째 수에서 j번째 수까지의 합을 구하는 프로그램을 작성하시오
// N은 1~100,000까지 가능하고, 합을 구해야 하는 횟수 M도 1~100,000까지 가능

#include <iostream>

using namespace std;

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >> suNo >> quizNo;
    int S[100001] = {};

    for(int i = 1; i <= suNo; i++) {
        int temp;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }

    for (int i = 0; i < quizNo; i++) {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start-1] << "\n";
    }

}