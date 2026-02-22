#include <iostream>
#include <vector>
using namespace std;

// 2차원 벡터에서 합배열을 만들려고 하면, (1,1)에서 (i, j)까지의 합을 구하는 합 배열을 만들고,
// 실제 문제의 답을 구하기 위해서는 (si, sj) ~ (ei, ej) 까지라고 한다면, sum(ei, ej) - sum(si, sj)를 하고, a(i, j)를 더해주면 되겠네.
// 그럼 합배열을 어떻게 구하는지가 문제인데, (i, j) 라고 한다면, (i, j)를 기준으로 (i - 1, j) + (i , j - 1)을 하고, (i - 1, j - 1)을 빼준다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A (N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sum (N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> A[i][j];
            sum[i][j] = A[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for(int i = 0; i < M; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1] << "\n";
    }
}