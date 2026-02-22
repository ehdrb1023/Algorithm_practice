#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬하고, 작은 수부터 포인터 지정해서 pointer로 지정해서, 걔보다 작은 수들을 i랑 j로 양 옆에 두고, 하나씩 줄이고 늘리면서 
// 지정해놓은 수가 만들어지는 순간 끝.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    int count = 0;

    for(int k = 2; k < N; k++) { // 어짜피 2번 째 수까지는 만들 수 없으니까 index 2부터 시작.
        int i = 0; int j = k - 1;

        while(i < j) {
            int sum = A[i] + A[j];
            if(sum == A[k]) {
                count++;
                break;
            } else if(sum < A[k]) {
                i++;
            } else {
                j--;
            }
        }
    }

    cout << count << "\n";
}