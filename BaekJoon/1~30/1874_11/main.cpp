#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N,0);
    vector<char> resultV;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> S;
    int current = 1;
    bool possible = true;

    for (int i = 0; i < A.size(); i++) {
        int target = A[i];

        while (current <= target) {
            S.push(current);
            resultV.push_back('+');
            current++;
        }

        if (S.top() == target) {
            S.pop();
            resultV.push_back('-');
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO\n";
    } else {
        for (char c : resultV) {
            cout << c << '\n';
        }
    }
}