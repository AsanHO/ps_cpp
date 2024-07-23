#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<int> m;

int main(int argc, char const *argv[]) {
    cin >> cnt;
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < cnt; i++) {
        int s;
        cin >> s;
        m.push_back(s);
    }

    int tsize = round((double)m.size() / 100 * 15);
    //
    sort(m.begin(), m.end());
    for (int i : m) {
    }
    m = vector<int>(m.begin() + tsize, m.end() - tsize);

    for (int i : m) {
    }

    cout << round((double)accumulate(m.begin(), m.end(), 0) / m.size());
    return 0;
}
