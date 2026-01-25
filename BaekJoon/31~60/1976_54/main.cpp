#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

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
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int connected;
            cin >> connected;
            if (connected == 1) union_nodes(i, j);
        }
    }

    int start;
    cin >> start;
    int root = find(start);
    bool possible = true;

    for (int i = 1; i < m; i++) {
        int next;
        cin >> next;
        if (root != find(next)) {
            possible = false;
            break;
        }
    }

    if (possible) cout << "YES";
    else cout << "NO";

    return 0;
}