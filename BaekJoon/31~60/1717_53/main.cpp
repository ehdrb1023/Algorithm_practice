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
    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            union_nodes(a, b);
        } else {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}