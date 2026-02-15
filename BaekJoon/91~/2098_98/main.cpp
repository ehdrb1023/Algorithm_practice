#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int W[16][16];
int dp[16][1 << 16];
const int INF = 1e9;

int solve(int curr, int visited) {
    if (visited == (1 << N) - 1) {
        if (W[curr][0] == 0) return INF;
        return W[curr][0];
    }

    if (dp[curr][visited] != -1) 
        return dp[curr][visited];

    dp[curr][visited] = INF;
    for (int next = 0; next < N; next++) {
        if (!(visited & (1 << next)) && W[curr][next] != 0) {
            dp[curr][visited] = min(dp[curr][visited], solve(next, visited | (1 << next)) + W[curr][next]);
        }
    }
    return dp[curr][visited];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cin >> W[i][j];
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (1 << 16); j++) 
            dp[i][j] = -1;
    }

    cout << solve(0, 1) << endl;
    return 0;
}