#include <iostream>
#include <vector>
using namespace std;

// 일단 첫 번째 자릿수부터 소수여야 되니까, 첫 번째 자리는 2, 3, 5, 7이어야 되고
// 두 번째는 최소 홀수여야 되니까 1, 3, 5, 7, 9
// 일단 DFS로 가야되니까 함수를 만들어야 되나.

static vector<int> A = {1, 3, 5, 7, 9};
static int N;

bool isPrime(int num) {
    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void DFS(int number, int i) {
    if(i == N) {
        if (isPrime(number)) {
            cout << number << "\n";
        }
    }

    for(int j = 0; j < 5; j++) {
        if(isPrime(number * 10 + A[j])) {
            DFS(number * 10 + A[j], i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}