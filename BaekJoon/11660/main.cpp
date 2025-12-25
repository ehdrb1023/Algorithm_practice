// 2차원 N X N 행렬을 만들고 (X1, Y1) ~ (X2, Y2) 까지의 합을 구한다

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Matrix (N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> Matrix[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1 - 1; i < x2; i++) {
            for(int j = y1 -1; j < y2; j++) {
                sum += Matrix[i][j];
            }
        }
        cout << sum << "\n";
    }
}