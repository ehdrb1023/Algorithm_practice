#include <iostream>
#include <vector>

using namespace std;

long long f[21];
bool visited[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++) 
        f[i] = f[i - 1] * i;

    cin >> q;

    if (q == 1) {
        long long k;
        cin >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visited[j]) 
                    continue;
                if (f[n - 1 - i] < k) {
                    k -= f[n - 1 - i];
                } else {
                    v[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) 
            cout << v[i] << " ";
    } else {
        vector<int> v(n);
        for (int i = 0; i < n; i++) 
            cin >> v[i];
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < v[i]; j++) {
                if (!visited[j]) {
                    ans += f[n - 1 - i];
                }
            }
            visited[v[i]] = true;
        }
        cout << ans;
    }

    return 0;
}