#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[20001];
int colors[20001];
bool ok;

void DFS(int node, int c) {
    colors[node] = c;
    for (int next : adj[node]) {
        if (colors[next] == 0) DFS(next, 3 - c);
        else if (colors[next] == c) ok = false;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) { adj[i].clear(); colors[i] = 0; }
        for (int i = 0; i < e; i++) {
            int u, v1; cin >> u >> v1;
            adj[u].push_back(v1); adj[v1].push_back(u);
        }
        ok = true;
        for (int i = 1; i <= v; i++) if (colors[i] == 0) DFS(i, 1);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}