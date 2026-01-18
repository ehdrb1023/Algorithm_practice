#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[10001];
bool visited[10001];
int cnt;

void BFS(int start) {
    queue<int> q; q.push(start); visited[start] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int next : adj[curr]) {
            if (!visited[next]) { visited[next] = true; cnt++; q.push(next); }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }
    vector<int> res; int maxVal = -1;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited)); cnt = 0;
        BFS(i);
        if (cnt > maxVal) { maxVal = cnt; res.clear(); res.push_back(i); }
        else if (cnt == maxVal) res.push_back(i);
    }
    for (int x : res) cout << x << " ";
    return 0;
}