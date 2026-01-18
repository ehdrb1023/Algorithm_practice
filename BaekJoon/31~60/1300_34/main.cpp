#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N, K; cin >> N >> K;
    long long start = 1, end = K, ans = 0;
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }
        if (cnt < K) start = mid + 1;
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}