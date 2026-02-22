#include <iostream>
using namespace std;

// 투포인터를 사용해서 start_index, end_index를 하나씩 이동해가면서 구합니다. 
// 근데 개념만 포인터지, 포인터나 벡터를 사용해서 접근하는 건 아님.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int count = 1;
    int sum = 1;
    int start_index = 1;
    int end_index = 1;

    while(end_index != N) {
        if (sum == N) {
            count++;
            end_index++;
            sum = sum + end_index;
        } else if(sum > N) {
            sum = sum - start_index;
            start_index++;
        } else {
            end_index++;
            sum = sum + end_index;
        }
    }
    cout << count << "\n";
}