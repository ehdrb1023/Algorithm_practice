#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long dp[201][201];
const long long MAX = 1000000000 + 7;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    for (int i = 0; i <= 200; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = min(MAX, dp[i - 1][j - 1] + dp[i - 1][j]);
        }
    }

    if (dp[n + m][m] < k) {
        cout << -1 << endl;
        return 0;
    }

    string result = "";
    int a_cnt = n;
    int z_cnt = m;

    for (int i = 0; i < n + m; i++) {
        if (a_cnt > 0) {
            long long temp = dp[a_cnt + z_cnt - 1][z_cnt];
            if (temp >= k) {
                result += 'a';
                a_cnt--;
            } else {
                result += 'z';
                k -= temp;
                z_cnt--;
            }
        } else {
            result += 'z';
        }
    }

    cout << result << endl;

    return 0;
}