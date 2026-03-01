#include <iostream>
#include <vector>
using namespace std;

// 이건 그래프 노드 하나에서 쭉 돌아봐야 되잖아? -> DFS이다.
// 잠시만 이건 계속 DFS로 파고 들어야 되니까 DFS 함수를 만들어서 계속 호출을 해줘야 된단 말이지.
// 그러면 vector 랑 변수들을 전역 변수로 빼줘야 겠는데.

static vector<vector<int>> A;
void DFS(int i);
static vector<bool> visited; // 방문했는지 여부를 확인해야하니까.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    } // 그래프를 인접리스트로 표현

    int count = 0;

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            count++;
            DFS(i);
        } // 결국 연결 요소를 구하는 거니까. 하나의 연결은 끝까지 true로 돌려버리고, false라는 건 새로운 연결 요소라는 의미니까 
    }

    cout << count << "\n";
}

void DFS(int i) {
    if(visited[i]) {
        return;
    }

    visited[i] = true;

    for(int j : A[i]) {
        if(!visited[j]) {
            DFS(j);
        }
    }
}

