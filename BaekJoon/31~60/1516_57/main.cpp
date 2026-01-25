#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> build_time(n + 1);
    vector<int> result(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> build_time[i];
        while (true) {
            int pre;
            cin >> pre;
            if (pre == -1) break;
            adj[pre].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = build_time[i];
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            indegree[next]--;
            result[next] = max(result[next], result[curr] + build_time[next]);
            if (indegree[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}