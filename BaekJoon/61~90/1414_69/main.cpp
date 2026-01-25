#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int parent[51];
int find(int a) { return (parent[a] == a) ? a : (parent[a] = find(parent[a])); }

int charToDist(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 27;
    return 0;
}

int main() {
    int n; cin >> n;
    vector<Edge> edges;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            int dist = charToDist(s[j]);
            total += dist;
            if (i != j && dist != 0) edges.push_back({i, j, dist});
        }
    }
    sort(edges.begin(), edges.end());

    long long mst_w = 0;
    int count = 0;
    for (auto& e : edges) {
        if (find(e.u) != find(e.v)) {
            parent[find(e.u)] = find(e.v);
            mst_w += e.w;
            count++;
        }
    }

    if (n > 1 && count != n - 1) cout << -1;
    else cout << total - mst_w;
    return 0;
}