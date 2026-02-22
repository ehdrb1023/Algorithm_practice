#include <iostream>
#include <queue>
using namespace std;

// 새로운 함수를 만들어서(구조체죠) 절대값으로 해서 우선순위를 재설정하는 걸 만들고
// 우선순위 큐를 이용하는 문제네요.

struct compare{
    bool operator()(int f, int s) {
        int first_abs = abs(f);
        int second_abs = abs(s);

        if(first_abs == second_abs) {
            return f > s;
        } else {
            return first_abs > second_abs;
        }
    }
}; // 요런 느낌으로 만들어주고.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, compare> q;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int req;
        cin >> req;

        if(req == 0) {
            if(q.empty()) {
                cout << "0\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(req);
        }
    }

}