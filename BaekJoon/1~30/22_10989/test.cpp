#include <iostream>
#include <vector>
using namespace std;

// 오름차순으로 정렬은 sort를 사용해도 되지만, 시간 제한에 걸릴 경우, 그냥 배열을 나올 수 범위만큼 만들고
// 입력 받는 순간 그 index의 배열 값을 0에서 1로 바꾸는 식으로 하고, 0부터 N까지 돌리면서 1인거 출력하면 된다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(10000001, 0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        A[num] = 1;
    }

    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 1) {
            cout << i << "\n";
        }
    }
}