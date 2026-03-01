#include <iostream>
#include <vector>
using namespace std;

int N, M;
int result[9];
bool visited[9];

void DFS(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[depth] = i;
            DFS(depth + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    DFS(0);
    return 0;
}