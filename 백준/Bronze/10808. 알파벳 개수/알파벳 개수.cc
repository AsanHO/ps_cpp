#include <bits/stdc++.h>

using namespace std;

int cnt[26];
string str;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> str;

    for (char a : str) {
        cnt[a - 97] += 1;
    }

    for (int i : cnt) {
        cout << i << " ";
    }

    return 0;
}
