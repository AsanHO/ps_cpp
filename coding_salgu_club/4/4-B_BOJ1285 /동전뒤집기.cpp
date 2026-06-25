
/*
동전의 최소개수를 구한다.
최소개수는 2개보다 작을수 없다. 최소 2개
n이 3개일때 마스킹은 6개까지 수행 2*3
*/
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

int n;
int min_result = 2100000000;
int map[21];
string s;
void dfs(int cnt) {
    if (cnt == n) {
        int total_h_cnt = 0;
        for (int mask = 1; mask < (1 << n); mask = mask << 1) {
            int h_cnt = 0;
            for (int i = 0; i < n; i++) {
                if (map[i] & mask) h_cnt++;
            }
            total_h_cnt += min(h_cnt, n - h_cnt);
        }
        min_result = min(min_result, total_h_cnt);
        return;
    }
    dfs(cnt + 1);
    map[cnt] = ~map[cnt];
    dfs(cnt + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int v = 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'T') {
                map[i] |= v;
            }
            v = v << 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << bitset<4>(map[i]) << endl;
    }

    dfs(0);
    cout << min_result << endl;
    return 0;
}