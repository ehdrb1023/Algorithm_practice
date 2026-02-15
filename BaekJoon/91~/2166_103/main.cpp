#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<long long, long long>> v(N);
    for (int i = 0; i < N; i++) 
        cin >> v[i].first >> v[i].second;

    double area = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        area += (v[i].first * v[j].second);
        area -= (v[j].first * v[i].second);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(area) / 2.0 << endl;

    return 0;
}