#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M;
int maze[101][101];
int dist[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (maze[nx][ny] == 1 && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1] << "\n";

    return 0;
}