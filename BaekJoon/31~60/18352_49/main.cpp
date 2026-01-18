#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, x; cin >> n >> m >> k >> x;
    vector<int> adj[300001], dist(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    queue<int> q; q.push(x); dist[x] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) { cout << i << "\n"; found = true; }
    }
    if (!found) cout << -1;
    return 0;
}