#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string s; cin >> s;
    stringstream ss(s);
    string sub;
    int res = 0;
    bool first = true;
    while (getline(ss, sub, '-')) {
        int sum = 0;
        stringstream ss2(sub);
        string num;
        while (getline(ss2, num, '+')) sum += stoi(num);
        if (first) { res += sum; first = false; }
        else res -= sum;
    }
    cout << res;
    return 0;
}