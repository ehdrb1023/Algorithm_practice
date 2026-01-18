#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int A[101][101];
static bool visited[101][101] = {false};
static int N, M;

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (A[nx][ny] != 0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    A[nx][ny] = A[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    BFS(0, 0);

    cout << A[N - 1][M - 1] << endl;

    return 0;
}