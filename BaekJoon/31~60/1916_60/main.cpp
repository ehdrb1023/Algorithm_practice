#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
vector<pair<int, int>> adj[1001];
int dist[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    for (int i = 1; i <= n; i++) dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < d) continue;

        for (auto &edge : adj[curr]) {
            int next = edge.first;
            int next_dist = d + edge.second;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    cout << dist[end];

    return 0;
}