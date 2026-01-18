#include <iostream>
#include <vector>
using namespace std;

struct Node { int b, p, q; };
vector<Node> adj[10];
long long ans[10];
bool visited[10];
long long lcmVal = 1;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void DFS(int curr) {
    visited[curr] = true;
    for (auto next : adj[curr]) {
        if (!visited[next.b]) {
            ans[next.b] = ans[curr] * next.q / next.p;
            DFS(next.b);
        }
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q; cin >> a >> b >> p >> q;
        adj[a].push_back({b, p, q});
        adj[b].push_back({a, q, p});
        lcmVal *= (p * q / gcd(p, q));
    }
    ans[0] = lcmVal;
    DFS(0);
    long long totalGcd = ans[0];
    for (int i = 1; i < n; i++) totalGcd = gcd(totalGcd, ans[i]);
    for (int i = 0; i < n; i++) cout << ans[i] / totalGcd << " ";
    return 0;
}