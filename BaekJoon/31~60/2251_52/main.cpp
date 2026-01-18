#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int cap[3]; 
bool visited[201][201];
bool ans[201];


int from[] = {0, 0, 1, 1, 2, 2};
int to[] = {1, 2, 0, 2, 0, 1};

void BFS() {
    queue<pair<int, int>> q;
    q.push({0, 0}); 
    visited[0][0] = true;
    ans[cap[2]] = true;

    while (!q.empty()) {
        int curr[3];
        curr[0] = q.front().first;
        curr[1] = q.front().second;
        curr[2] = cap[2] - curr[0] - curr[1];
        q.pop();

        for (int i = 0; i < 6; i++) {
            int next[3] = {curr[0], curr[1], curr[2]};

            int amount = min(next[from[i]], cap[to[i]] - next[to[i]]);
            next[from[i]] -= amount;
            next[to[i]] += amount;

            if (!visited[next[0]][next[1]]) {
                visited[next[0]][next[1]] = true;
                q.push({next[0], next[1]});
                if (next[0] == 0) { 
                    ans[next[2]] = true;
                }
            }
        }
    }
}

int main() {
    cin >> cap[0] >> cap[1] >> cap[2];

    BFS();

    for (int i = 0; i <= cap[2]; i++) {
        if (ans[i]) cout << i << " ";
    }

    return 0;
}