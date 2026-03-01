#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N+1); // 바깥쪽 벡터의 size만 resize. 열의 수가 바뀐다는 것.
    visited = vector<bool>(N+1, false);

    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    int count = 0;

    for (int i = 1; i < N + 1; i++) {
        if (!visited[i]) {
            count++;
            DFS(i);
        }
    }
    cout << count << "\n";
}

void DFS(int v) {
    if (visited[v]) {
        return;
    }
    // 1. v를 true로 바꾸기.
    visited[v] = true;
    for (int i : A[v]) {
        if (visited[i] == false) { // v의 연결리스트에 있는 i에 한해서 false면 그거에 또 DFS(i) 실행 -> 말 그대로 depth first search
            DFS(i);
        }
    }
}
