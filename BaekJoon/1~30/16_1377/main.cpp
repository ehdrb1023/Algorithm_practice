#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int maxDiff = 0;
    for (int i = 0; i < N; i++) {
        int originalIndex = A[i].second;
        maxDiff = max(maxDiff, originalIndex - i);
    }

    cout << maxDiff + 1 << '\n';
}