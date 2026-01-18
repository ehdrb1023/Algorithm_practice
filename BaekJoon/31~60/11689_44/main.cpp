#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            result -= result / p;
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) result -= result / n;
    cout << result;
    return 0;
}