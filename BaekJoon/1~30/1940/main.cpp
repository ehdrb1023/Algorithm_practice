// 서로 다른 수 N개가 주어졌을 때, 어떤 자연수 M을 만들 수 있는 2개의 숫자 조합이 N개 안에 몇 개가 있는지 구하시오
// 1 <= N <= 15,000 , 1 <= M <= 10,000,000 N 안에 있는 수는 100,000보다 작은 수. 2초

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;


    vector<int> number(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }

    sort(number.begin(), number.end());

    int count = 0;
    int i = 0;
    int j = N - 1;

    while(i < j) {
        if(number[i] + number[j] > M) {
            j--;
        } else if(number[i] + number[j] < M) {
            i++;
        } else {
            count++;
            i++;
            j--;
        }
    }

    cout << count << "\n";
}