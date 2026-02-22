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
    vector<int> digits;
    
    if (N == 0) {
        digits.push_back(0);
    }

    while (N > 0) {
        digits.push_back(N % 10);

        N = N / 10;
    }

    sort(digits.begin(), digits.end(), greater<int>());

    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i];
    }

    cout << "\n";

    return 0;
}