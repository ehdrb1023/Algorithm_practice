// 기말고사 과목 수와 점수를 입력받고, 모든 점수를 최고점으로 나누고 100을 곱한 값으로 변환
// 이렇게 조작한 점수들의 평균을 구하는 프로그램을 작성하시오

#include <iostream>

using namespace std;

int main() {

    int N = 0;
    cin >> N;
    int A[1000];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    double sum = 0;
    double max = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > max) {
            max = A[i];
        }
        sum += A[i];
    }

    double result = sum * 100.0 / max / N;
    cout << result << "\n";
}