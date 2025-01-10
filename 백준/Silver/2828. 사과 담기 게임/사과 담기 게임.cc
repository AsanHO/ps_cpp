#include <bits/stdc++.h>

using namespace std;

vector<int> s;
int n, m, j;
int result = 0;
void print(vector<int> v) {
    for (auto i : v) {
        cout << i;
    }
    cout << '\n';
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> j;

    pair basketRange = make_pair(1, m);

    for (int i = 0; i < j; i++) {
        int target;
        cin >> target;
        // cout << target << basketRange.first << basketRange.second << "\n";
        // 범위에 포함되지 않으면 이동
        if (basketRange.first > target || basketRange.second < target) {
            
            // cout << "포함안됨!" << "\n";
            // 타겟보다 왼쪽에 있으면 
            if (basketRange.first > target) {
                int targetRange = basketRange.first - target;
                result += targetRange;
                basketRange.first = basketRange.first - targetRange;
                basketRange.second = basketRange.second - targetRange;
            } else {
                int targetRange = target - basketRange.second;
                result += targetRange;
                basketRange.first = basketRange.first + targetRange;
                basketRange.second = basketRange.second + targetRange;
            }
            // cout << "이동완료" << "\n";
        }
    }

    cout << result;
    return 0;
}
