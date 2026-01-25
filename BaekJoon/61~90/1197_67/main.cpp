#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent[10001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void union_nodes(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= v; i++) parent[i] = i;

    long long ans = 0;
    for (int i = 0; i < e; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            union_nodes(edges[i].u, edges[i].v);
            ans += edges[i].w;
        }
    }
    cout << ans;
    return 0;
}