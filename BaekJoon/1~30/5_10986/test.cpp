#include <iostream>
#include <vector>
using namespace std;

// 배열을 만들고, 이를 합배열로 만든 다음, M으로 나누고자 할 때, 나머지가 같은 i와 j가 있다면 i + 1 ~ j까지의 합이 M으로 나누어 떨어진다고 합니다.
// 그걸 이용해서 구성해봅시다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<long> A(N , 0);
    vector<long> sum(N , 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(i == 0) {
            sum[i] = A[i];
        } else {
            sum[i] = sum[i - 1] + A[i];
        }
    }

    for(int i = 0; i < N; i++) {
        sum[i] = sum[i] % M;
    }

    long count = 0;
    vector<long> remainder(M, 0);
    for(int i = 0; i < N; i++) {
        if (sum[i] == 0) {
            count++;
        }
        remainder[sum[i]]++;
    }

    for(int i = 0; i < M; i++) {
        if (remainder[i] > 1) {
            count = count + ((remainder[i] * (remainder[i] - 1)) / 2);
        }
    }
    cout << count << "\n";
}