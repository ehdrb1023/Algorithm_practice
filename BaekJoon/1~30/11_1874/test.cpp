#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 이건 좀 규칙을 알아야 되네.
// 현재 수열 값이 자연수보다 크거나 같으면, 자연수를 계속 증가시키면서 push도 계속 해.
// 그리고 해당 수열 값이 push 되었으면 pop까지 함.
// 현재 수열값 < 자연수면 pop으로 스택에 있는 값을 꺼내서 원하는 수열값이 나올 때까지 함.
// 근데 이 때 top에 있는 수가, 원하는 수열값보다 작으면 이미 답이 없으니까 'NO' 출력하도록

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<char> result; // pop이랑 push 저장하는거죠. 그니까 + 랑 -

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> B;
    int num = 1;
    int possible = 1; // 1이면 성공이 되어 있는 상태고, NO가 되면 이것도 같이 0으로 만들어서 굳이 +랑 -를 출력 안하도록

    for(int i = 0; i < A.size(); i++) {
        int current = A[i];

        if(current >= num) {
            while(current >= num) {
                B.push(num);
                num++;
                result.push_back('+');
            }
            B.pop();
            result.push_back('-');
        } else {
            int n = B.top();
            B.pop();
            if (n > current) {
                cout << "NO" << "\n";
                possible = 0;
                break;
            } else {
                result.push_back('-');
            }
        }
    }
    if(possible == 1) {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << "\n";
        }
    }
}