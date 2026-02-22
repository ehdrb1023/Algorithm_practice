#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 윈도우 슬라이드로 하면 될 것 같고
// index 정렬? 활용해서 진행하면 될 것 같네.

int charToIndex(char c) {
    if (c == 'A') {
        return 0;
    }
    if (c == 'C') {
        return 1;
    }
    if (c == 'G') {
        return 2;
    }
    if (c == 'T') {
        return 3;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str;
    cin >> str;

    int req[4];
    for (int i = 0; i < 4; i++) {
        cin >> req[i];
    }

    int current[4] = {0, 0, 0, 0};
    int count = 0;

    for (int i = 0; i < M; i++) {
        int idx = charToIndex(str[i]);
        current[idx]++;
    }

    bool first_valid = true;
    for (int i = 0; i < 4; i++) {
        if (current[i] < req[i]) {
            first_valid = false;
        }
    }

    if (first_valid) {
        count++;
    }

    for (int i = M; i < N; i++) {
        int add_idx = charToIndex(str[i]);
        int del_idx = charToIndex(str[i - M]);

        current[add_idx]++;

        current[del_idx]--;

        bool current_valid = true;
        for (int j = 0; j < 4; j++) {
            if (current[j] < req[j]) {
                current_valid = false;
            }
        }

        if (current_valid) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}