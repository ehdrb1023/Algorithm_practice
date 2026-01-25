#include <iostream>
#include <vector>
#include <numeric>

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

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> truth(t);
    for (int i = 0; i < t; i++) cin >> truth[i];

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int p_num;
        cin >> p_num;
        parties[i].resize(p_num);
        for (int j = 0; j < p_num; j++) {
            cin >> parties[i][j];
            if (j > 0) union_nodes(parties[i][j - 1], parties[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool can_lie = true;
        for (int person : parties[i]) {
            for (int t_person : truth) {
                if (find(person) == find(t_person)) {
                    can_lie = false;
                    break;
                }
            }
            if (!can_lie) break;
        }
        if (can_lie) ans++;
    }

    cout << ans;
    return 0;
}