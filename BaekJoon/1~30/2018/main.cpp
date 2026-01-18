// 어떠한 자연수 N을 연속된 자연수의 합으로 나태내는 가짓수를 출력하는 코드를 작성하시오
// 2초

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;

    while (end_index != N) {
        if(sum == N) {
            count++;
            end_index++;
            sum = sum + end_index;
        } else if (sum > N) {
            sum = sum - start_index;
            start_index++;
        } else {
            end_index++;
            sum = sum + end_index;
        }
    }

    cout << count << "\n";

}
