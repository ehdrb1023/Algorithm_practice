#include <iostream>
#include <vector>

using namespace std;

long long dp[1000001];
const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}