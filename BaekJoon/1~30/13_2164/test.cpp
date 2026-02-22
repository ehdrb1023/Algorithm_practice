#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }
    while(q.size() > 1) {
        q.pop(); // 간단해서 할 게 따로 없고, 이 while문이 규칙이네.
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << "\n";
}