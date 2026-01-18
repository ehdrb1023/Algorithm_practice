#include <iostream>
#include <vector>
using namespace std;

void mergesort(int s, int e);
static vector<int> A;
static vector<int> temp;
static long long result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N);
    temp.resize(N);
    result = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mergesort(0, N - 1);

    cout << result << '\n';
}

void mergesort(int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergesort(s, mid);
    mergesort(mid + 1, e);

    int left = s;
    int right = mid + 1;
    int index = s;

    while (left <= mid && right <= e) {
        if (A[left] <= A[right]) {
            temp[index++] = A[left++];
        } else {
            result += (mid - left + 1);
            temp[index++] = A[right++];
        }
    }

    while (left <= mid) {
        temp[index++] = A[left++];
    }

    while (right <= e) {
        temp[index++] = A[right++];
    }

    for (int i = s; i <= e; i++) {
        A[i] = temp[i];
    }
}