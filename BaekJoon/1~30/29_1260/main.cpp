#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int node);
void BFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    A.resize(N + 1);


    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }


    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }


    visited.assign(N + 1, false);
    DFS(V);
    cout << "\n";

    visited.assign(N + 1, false);
    BFS(V);
    cout << "\n";

    return 0;
}


void DFS(int node) {
    cout << node << " ";
    visited[node] = true;
    for (int next : A[node]) {
        if (!visited[next]) {
            DFS(next);
        }
    }
}


void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int next : A[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}