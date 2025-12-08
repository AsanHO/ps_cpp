#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, C;
int a[1001];
vector<pair<int, int>> v;
map<int, int> mp, mp_inputIndex;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp_inputIndex[a[i]] == 0) mp_inputIndex[a[i]] = i + 1;
    }
    // for (auto i : mp_inputIndex) {
    //     // cout << i.first << " " << i.second << endl;
    //     // v.push_back(make_pair(i.first, i.second));
    // }
    for (auto i : mp) {
        // cout << i.first << " " << i.second << endl;
        v.push_back(make_pair(i.first, i.second));
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return mp_inputIndex[a.first] < mp_inputIndex[b.first];
        }
        return a.second > b.second;
    });
    for (auto i : v) {
        for (int j = 0; j < i.second; j++) {
            cout << i.first << " ";
        }
    }

    return 0;
}