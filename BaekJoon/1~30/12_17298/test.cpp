#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 정답 stack을 만들고, 새로운 index의 값이 top보다 크면 top을 pop해서 그 정답 vector의 index에 그 값을 저장.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N , 0);
    vector<int> result(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> s;
    s.push(0); // 이렇게 index를 푸쉬해서 각을 보는거지.

    for (int i = 1; i < N; i++) {
        while(!s.empty() && A[s.top()] < A[i]) {
            result[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        result[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}