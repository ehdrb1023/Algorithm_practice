#include <iostream>
#include <vector>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    long long a, b, c, x, y; cin >> a >> b >> c;
    long long d = extended_gcd(a, b, x, y);
    if (c % d != 0) cout << -1;
    else cout << x * (c / d) << " " << y * (c / d);
    return 0;
}