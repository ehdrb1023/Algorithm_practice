#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    for (int i = N; ; i++) {
        if (isPalindrome(i) && isPrime(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}