#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1, 0);
    vector<int> sum(N + 1, 0); // 구갑 합은 합 배열을 이용해서 시간 복잡도를 줄이는 방향으로.

    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        A[i] = num;
        sum[i] = sum[i - 1] + num;
    }

    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << "\n"; // s ~ e까지의 구간합은 합 배열 e에서 합배열 s - 1을 빼면 된다.
    }
}