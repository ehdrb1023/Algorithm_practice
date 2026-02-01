#include <iostream>

using namespace std;

long long dp[31][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 30; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (i == j) 
                dp[i][j] = 1;
            else 
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << "\n";
    }

    return 0;
}