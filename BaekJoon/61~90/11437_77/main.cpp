#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[50001];
int parent[50001];
int depth[50001];
bool visited[50001];
int n, m;

void dfs(int cur, int d) {
    visited[cur] = true;
    depth[cur] = d;
    for (int next : adj[cur]) {
        if (visited[next]) 
            continue;
        parent[next] = cur;
        dfs(next, d + 1);
    }
}

int lca(int u, int v) {
    while (depth[u] != depth[v]) {
        if (depth[u] > depth[v]) 
            u = parent[u];
        else v = parent[v];
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}