// 주어진 N개의 수에서 다른 두 수의 합으로 표현되는 수가 있다면 그 수를 "좋은 수"라고 할 때, N개의 수 중 좋은 수는 몇 개인지 구하시오
// 1 <= N <= 2000, N 내부의 값은 절대값이 1,000,000,000보다 작거나 같은 정수.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int Result = 0;

    for(int k = 0; k < N; k++) {
        int i = 0;
        int j = N-1;
        int L = A[k];

        while(i < j) {
            if (A[i] + A[j] == L) {
                if(i != k && j != k) {
                    Result++;
                    break;
                } else if (i == k) {
                    i++;
                } else if (j == k) {
                    j--;
                }
            } else if (A[i] + A[j] < L) {
                i++;
            } else {
                j--;
            }
        }
    }

    cout << Result << "\n";
}