#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge { int to, dist; };
vector<Edge> adj[100001];
bool visited[100001];
int maxDist = 0, farNode = 0;

void DFS(int node, int dist) {
    if (visited[node]) return;
    visited[node] = true;

    if (maxDist < dist) {
        maxDist = dist;
        farNode = node;
    }

    for (auto& edge : adj[node]) {
        DFS(edge.to, dist + edge.dist);
    }
}

int main() {
    int V; cin >> V;
    for (int i = 0; i < V; i++) {
        int u; cin >> u;
        while (true) {
            int v, d; cin >> v;
            if (v == -1) break;
            cin >> d;
            adj[u].push_back({v, d});
        }
    }
    memset(visited, false, sizeof(visited));
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    DFS(farNode, 0);
    cout << maxDist;
    return 0;
}