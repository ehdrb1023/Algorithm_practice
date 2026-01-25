#include <iostream>
#include <vector>

using namespace std;

vector<int> child[51];
int root, deleted_node, leaf_count = 0;

void dfs(int curr) {
    if (curr == deleted_node) return;
    int children = 0;
    for (int next : child[curr]) {
        if (next == deleted_node) continue;
        dfs(next);
        children++;
    }
    if (children == 0) leaf_count++;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p == -1) root = i;
        else child[p].push_back(i);
    }
    cin >> deleted_node;
    if (deleted_node != root) dfs(root);
    cout << leaf_count;
    return 0;
}