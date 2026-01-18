#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) cin >> A[i].second >> A[i].first; // 종료 시간 기준 정렬 위해 swap 저장
    sort(A.begin(), A.end());
    int count = 0, end = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second >= end) {
            end = A[i].first;
            count++;
        }
    }
    cout << count;
    return 0;
}