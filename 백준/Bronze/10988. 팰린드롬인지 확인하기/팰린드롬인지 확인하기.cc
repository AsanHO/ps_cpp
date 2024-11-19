#include <bits/stdc++.h>

using namespace std;

string word;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> word;
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    if (reversedWord == word) {
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}
