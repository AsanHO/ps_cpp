#include <bits/stdc++.h>

using namespace std;

int cnt;
string pat;
string pat1;
string pat2;
bool is1 = true;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> cnt;

    cin >> pat;
    for (char w : pat) {
        if (w == '*') {
            is1 = false;
            continue;
        }
        if (is1) {
            pat1 += w;
        } else {
            pat2 += w;
        }
    }

    for (int i = 0; i < cnt; i++) {
        string name;
        cin >> name;
        if (name.rfind(pat1, 0) == 0) {
            string reversedName = name.substr(pat1.length());
            string reversedpat2 = pat2;

            reverse(reversedName.begin(), reversedName.end());
            reverse(reversedpat2.begin(), reversedpat2.end());
            if (reversedName.rfind(reversedpat2, 0) == 0) {
                cout << "DA" << "\n";
                continue;
            }
        }
        cout << "NE" << "\n";
    }
}
