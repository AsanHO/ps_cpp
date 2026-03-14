#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
완탐 -> 인덱스 기반
*/
vector<int> num;
vector<char> open_str;
int n;
int result = -987654321;
string s;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int oper(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void solve(int here, int _num) {
    // cout << here << " " << _num << endl;
    if (here == num.size() - 1) {  //
        // cout << "_num" << _num << endl;
        result = max(result, _num);
        // cout << result << endl;
        return;
    }
    solve(here + 1, oper(open_str[here], _num, num[here + 1]));

    if (here + 2 <= num.size() - 1) {
        int temp = oper(open_str[here + 1], num[here + 1], num[here + 2]);  // 뒤에걸 먼저 계산 후
        // cout << "뒤에거" << num[here + 1] << open_str[here + 1] << num[here] << " -> " << temp << endl;
        // cout << "앞에거" << _num << open_str[here] << temp << " -> " << oper(open_str[here], _num, temp) << endl;
        solve(here + 2, oper(open_str[here], _num, temp));  // 앞의 거 계산
    }
}

int main() {
    fastIO();
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            num.push_back(s[i] - '0');
        else
            open_str.push_back(s[i]);
    }
    // for (auto n : num) cout << n << " ";
    // cout << endl;
    // for (auto n : open_str) cout << n << " ";
    // cout << endl;
    solve(0, num[0]);
    cout << result << endl;
    return 0;
}
