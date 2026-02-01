#include <iostream>

using namespace std;

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k < 0 || k > n) {
        cout << 0 << endl;
        return 0;
    }

    int result = factorial(n) / (factorial(k) * factorial(n - k));
    cout << result << endl;

    return 0;
}