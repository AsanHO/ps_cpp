#include <bits/stdc++.h>

using namespace std;

int t = 0;
int nums[1000001];
long long n, i, evenC = 0, oddC = 0, cnt0 = 0, cnt1 = 0;
// 홀수를 왼쪽으로 밀어넣기
// 짝수를 왼쪽으로 밀어넣기
int main() {
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> nums[i];
    }
    for (i = 0; i < t; i++) {
        if (nums[i] % 2) {
            oddC++;
            cnt0 += evenC;
        } else {
            evenC++;
            cnt1 += oddC;
        }
        }
    cout << min(cnt0, cnt1);

    return 0;
}
