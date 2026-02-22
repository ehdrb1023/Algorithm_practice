#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 얘도 투포인터 활용해서, 정렬하고, 양 옆에서 구해가면 되겠네.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    cin >> N >> M;
    vector<int> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int start_index = 0;
    int end_index = N - 1;
    int sum = 0;
    int count = 0;

    while(start_index < end_index) {
        sum = A[start_index] + A[end_index];
        if(sum == M) {
            count++;
            start_index++;
            end_index--;
        } else if(sum < M) {
            start_index++;
        } else {
            end_index--;
        }
    }

    cout << count << "\n";
}