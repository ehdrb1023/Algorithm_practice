#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive ;
void DFS(int v, int number);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N);
    visited.resize(N, false);

    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    arrive = false;

    for(int i = 0; i < N; i++) {
        DFS(i, 1);
        if(arrive) {
            break;
        }
    }

    if(arrive) {
        cout << "1" << "\n";
    } else {
        cout << "0" << "\n";
    }
}

void DFS(int v, int number) {
    if(number == 5) {
        arrive = true;
        return;
    }

    if(visited[v]) {
        return;
    }

    visited[v] = true;

    for(int i : A[v]) {
        if(!visited[i]) {
            DFS(i, number + 1);
            if(arrive) {
                break;
            }
        }
    }
    visited[v] = false;
}