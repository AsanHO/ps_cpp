#include <bits/stdc++.h>

using namespace std;
int cnt;
map<char, pair<char, char> > tree;

void preOrder(char alphabet) {
    if (alphabet == '.') return;
    cout << alphabet;
    preOrder(tree[alphabet].first);
    preOrder(tree[alphabet].second);
}

void inOrder(char alphabet) {
    if (alphabet == '.') return;
    inOrder(tree[alphabet].first);
    cout << alphabet;
    inOrder(tree[alphabet].second);
}

void postOrder(char alphabet) {
    if (alphabet == '.') return;
    postOrder(tree[alphabet].first);
    postOrder(tree[alphabet].second);
    cout << alphabet;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root].first = left;
        tree[root].second = right;
    }
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');

    return 0;
}
