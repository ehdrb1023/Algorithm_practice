#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> lesson(N);
    int start = 0, end = 0;
    for (int i = 0; i < N; i++) {
        cin >> lesson[i];
        if (start < lesson[i]) start = lesson[i];
        end += lesson[i];
    }
    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0, count = 0;
        for (int i = 0; i < N; i++) {
            if (sum + lesson[i] > mid) {
                count++;
                sum = 0;
            }
            sum += lesson[i];
        }
        if (sum != 0) count++;
        if (count > M) start = mid + 1;
        else end = mid - 1;
    }
    cout << start;
    return 0;
}