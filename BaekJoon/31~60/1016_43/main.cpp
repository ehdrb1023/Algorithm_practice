#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long min, max; cin >> min >> max;
    vector<bool> check(max - min + 1, false);
    for (long long i = 2; i * i <= max; i++) {
        long long square = i * i;
        long long start = min / square;
        if (min % square != 0) start++;
        for (long long j = start; square * j <= max; j++) {
            check[square * j - min] = true;
        }
    }
    int count = 0;
    for (int i = 0; i <= max - min; i++) {
        if (!check[i]) count++;
    }
    cout << count;
    return 0;
}
