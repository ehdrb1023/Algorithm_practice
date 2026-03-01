#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> A[1001];
bool visited[1001];

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";

    for (int next : A[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : A[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    // DFS 수행
    dfs(V);
    cout << "\n";

    // visited 배열 초기화 후 BFS 수행
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    
    bfs(V);
    cout << "\n";

    return 0;
}