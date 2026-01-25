#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
struct Edge {
    int from, to, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<long long> dist(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    dist[1] = 0;
    bool cycle = false;

    for (int i = 1; i <= n; i++) {
        for (auto& e : edges) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == n) cycle = true;
            }
        }
    }

    if (cycle) cout << -1;
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
    return 0;
}