#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}