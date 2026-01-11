#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> A(str.size(), 0);

    for (int i = 0; i < str.size(); i++) {
        A[i] = str[i] - '0';
    }

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < str.length() - 1 - i; j++) {
            if (A[j] < A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }

    for (int i = 0; i < str.length(); i++) {
        cout << A[i];
    }

}