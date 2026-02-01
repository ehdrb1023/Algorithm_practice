#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    
    vector<int> count(m);
    int total = 0;
    for (int i = 0; i < m; i++) {
        cin >> count[i];
        total += count[i];
    }

    int k;
    cin >> k;

    double total_prob = 0.0;
    for (int i = 0; i < m; i++) {
        if (count[i] < k) 
            continue;

        double current_prob = 1.0;
        for (int j = 0; j < k; j++) {
            current_prob *= (double)(count[i] - j) / (total - j);
        }
        total_prob += current_prob;
    }

    cout.precision(16);
    cout << fixed << total_prob << endl;

    return 0;
}