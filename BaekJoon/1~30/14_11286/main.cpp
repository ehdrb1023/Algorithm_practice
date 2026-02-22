#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator() (int a, int b) {
        int absA = abs(a);
        int absB = abs(b);
        if (absA == absB) {
            return a > b;
        } else {
            return absA > absB;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, compare> pq;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        if (now == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(now);
        }
    }
}