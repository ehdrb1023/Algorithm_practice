#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> resultV(N, -1);
    stack<int> S;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        while (!S.empty() && A[S.top()] < A[i]) {
            resultV[S.top()] = A[i];
            S.pop();
        }
        S.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << resultV[i] << ' ';
    }
}