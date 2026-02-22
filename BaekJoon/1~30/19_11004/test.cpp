#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 추가 함수들을 만들어서 완성하는 문제라, 가이드라인을 보고 완성하는 방향으로.
void swap(vector<int> &A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(vector<int> &A, int s, int e) {
    if (s + 1 == e) {
        if (A[s] > A[e]) {
            swap(A, s, e);
        }
        return e;
    }

    int middle = (s + e) / 2;
    swap(A, s, middle);
    int pivot = A[s];
    int i = s + 1;
    int j = e;

    while (i <= j) {
        while (j >= s + 1 && pivot < A[j]) {
            j--;
        }

        while (i <= e && pivot > A[i]) {
            i++;
        }

        if (i <= j) {
            swap(A, i++, j--);
        }
    }

    A[s] = A[j];
    A[j] = pivot;
    return j;
}

void quicksort(vector<int> &A, int s, int e, int k) {
    if (s < e) {
        int pivot = partition(A, s, e);
        if (pivot == k) {
            return;
        }
        else if (k < pivot) {
            quicksort(A, s, pivot - 1, k);
        }
        else {
            quicksort(A, pivot + 1, e, k);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    quicksort(A, 0, N - 1, K - 1);

    cout << A[K - 1] << "\n";

    return 0;
}