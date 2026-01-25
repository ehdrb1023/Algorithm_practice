#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = -1e18;
struct Edge {
    int from, to, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, e, m;
    cin >> n >> s >> e >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> city_money(n);
    for (int i = 0; i < n; i++) cin >> city_money[i];

    vector<long long> dist(n, INF);
    dist[s] = city_money[s];

    for (int i = 0; i < n + 100; i++) {
        for (auto& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] < dist[edge.from] + city_money[edge.to] - edge.cost) {
                dist[edge.to] = dist[edge.from] + city_money[edge.to] - edge.cost;
                if (i >= n - 1) dist[edge.to] = 1e18; 
            }
        }
    }

    if (dist[e] == INF) cout << "gg";
    else if (dist[e] >= 1e17) cout << "Gee";
    else cout << dist[e];

    return 0;
}