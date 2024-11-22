#include <bits/stdc++.h>

using namespace std;

string T;
string fail = "I'm Sorry Hansoo";
map<char, int> dic;
set<char> alphas;
int oddCount = 0;
string leftWord;
string rightWord;
string middleWord;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // 펠린드롬이 되려면 모두 짝수이거나 하나만 홀수이어야함.
    cin >> T;
    for (char c : T) {
        dic[c] += 1;
        alphas.insert(c);
    }

    for (char alpha : alphas) {
        if (dic[alpha] % 2 != 0) {
            oddCount += 1;
        }
        if (oddCount > 1) {
            cout << fail;
            return 0;
        }
    }
    for (char alpha : alphas) {
        if (dic[alpha] % 2 != 0) {
            middleWord += alpha;
        }
        for (int i = 0; i < dic[alpha] / 2; i++) {
            leftWord += alpha;
            rightWord += alpha;
        }
        }
    reverse(rightWord.begin(), rightWord.end());
    cout << leftWord << middleWord << rightWord;
    return 0;
}
