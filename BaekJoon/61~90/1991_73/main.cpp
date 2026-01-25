#include <iostream>

using namespace std;

struct Node {
    char left, right;
};

Node tree[26];

void preorder(char curr) {
    if (curr == '.') return;
    cout << curr;
    preorder(tree[curr - 'A'].left);
    preorder(tree[curr - 'A'].right);
}

void inorder(char curr) {
    if (curr == '.') return;
    inorder(tree[curr - 'A'].left);
    cout << curr;
    inorder(tree[curr - 'A'].right);
}

void postorder(char curr) {
    if (curr == '.') return;
    postorder(tree[curr - 'A'].left);
    postorder(tree[curr - 'A'].right);
    cout << curr;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char p, l, r; cin >> p >> l >> r;
        tree[p - 'A'] = {l, r};
    }
    preorder('A'); cout << "\n";
    inorder('A'); cout << "\n";
    postorder('A'); cout << "\n";
    return 0;
}