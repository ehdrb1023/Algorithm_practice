#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        s.insert(str);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        string query; cin >> query;
        if (s.count(query)) ans++;
    }
    cout << ans;
    return 0;
}