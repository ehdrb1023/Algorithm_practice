#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> pos, neg;
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x > 1) pos.push_back(x);
        else if (x == 1) one++;
        else if (x == 0) zero++;
        else neg.push_back(x);
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    long long res = one;
    for (int i = 0; i < (int)pos.size(); i++) {
        if (i + 1 < pos.size()) { res += (pos[i] * pos[i+1]); i++; }
        else res += pos[i];
    }
    for (int i = 0; i < (int)neg.size(); i++) {
        if (i + 1 < neg.size()) { res += (neg[i] * neg[i+1]); i++; }
        else if (zero == 0) res += neg[i];
    }
    cout << res;
    return 0;
}