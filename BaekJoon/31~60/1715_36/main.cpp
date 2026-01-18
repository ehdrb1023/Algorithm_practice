#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int data; cin >> data;
        pq.push(data);
    }
    int sum = 0;
    while (pq.size() > 1) {
        int d1 = pq.top(); pq.pop();
        int d2 = pq.top(); pq.pop();
        sum += (d1 + d2);
        pq.push(d1 + d2);
    }
    cout << sum;
    return 0;
}