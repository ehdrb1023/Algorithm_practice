#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int s, int e);
static vector<int> A;
static vector<int> temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N);
    temp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mergeSort(0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << A[i] << '\n';
    }
}

void mergeSort(int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(s, mid);
    mergeSort(mid + 1, e);

    int left = s;
    int right = mid + 1;
    int index = s;

    while (left <= mid && right <= e) {
        if (A[left] <= A[right]) {
            temp[index++] = A[left++];
        } else {
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