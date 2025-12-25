// N개의 수가 주어졌을 때, 연속된 부분의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오
// N 1~1000000 , M 2~1000, 각각의 수 A 0~10^9

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long> S(N,0);
    vector<long> C(M,0);
    long answer = 0;
    cin >> S[0];

    for(int i = 1; i < N; i++) {
        int temp = 0;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }

    for(int i = 0; i < N; i++) {
        int remainder = S[i] % M;
        if(remainder == 0) {
            answer++;
        }
        C[remainder]++; // index를 int처럼 사용하는 케이스. 특정 나머지의 개수가 얼마인지를 index로 이동만 하면 알 수 있게.
    }

    for(int i = 0; i < M; i++) {
        if (C[i] > 1) {
            answer += (C[i] * (C[i]-1)) / 2;
        }
    }

    cout << answer << "\n";

}