#include <iostream>

using namespace std;

int N;
int ans = 0;
int col[15];

bool isSafe(int row) {
    for (int i = 0; i < row; i++) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i) {
            return false;
        }
    }
    return true;
}

void backtracking(int row) {
    if (row == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[row] = i; 
        
        if (isSafe(row)) { 
            backtracking(row + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    backtracking(0);

    cout << ans << "\n";

    return 0;
}