#include <iostream>
using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int S, P;
    cin >> S >> P;
    int Result = 0;
    string A;
    cin >> A;

    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) {
        checkSecret++;
        }
    }
    for (int i = 0; i < P; i++) {
        Add(A[i]);
    }
    if(checkSecret == 4) {
        Result++;
    }
    for (int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);
        if (checkSecret == 4) {
            Result++;
        }
    }
    cout << Result << "\n";

}

void Add (char c) {
    switch(c) {
        case 'A':
            myArr[0]++;
    }
}