#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long A, B; cin >> A >> B;
    vector<bool> isPrime(10000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 10000000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 10000000; j += i) isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i <= 10000000; i++) {
        if (isPrime[i]) {
            long long temp = i;
            while ((double)i <= (double)B / temp) { // 오버플로우 방지
                if ((double)i >= (double)A / temp) count++;
                temp *= i;
            }
        }
    }
    cout << count;
    return 0;
}