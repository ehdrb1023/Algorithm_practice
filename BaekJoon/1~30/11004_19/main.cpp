#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& A, int S, int E, int K);
int partition(vector<int>& A, int S, int E);
void swap(vector<int>& A, int i, int j);

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

    quickSort(A, 0, N - 1, K - 1);

    cout << A[K - 1] << '\n';
}

void quickSort(vector<int>& A, int S, int E, int K) {
    if (S >= E) {
        return;
    }

    int pivot = partition(A, S, E);

    if (pivot == K) {
        return;
    } else if (pivot < K) {
        quickSort(A, pivot + 1, E, K);
    } else {
        quickSort(A, S, pivot - 1, K);
    }
}

int partition(vector<int>& A, int S, int E) {
    int pivot = A[E];
    int i = S - 1;

    for (int j = S; j < E; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i + 1, E);
    return i + 1;
}

void swap(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}