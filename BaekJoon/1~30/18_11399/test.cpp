#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> sum(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            sum[i] = A[i];
        }
        else {
            sum[i] = sum[i - 1] + A[i];
        }
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total = total + sum[i];
    }

    cout << total << "\n";

    return 0;
}