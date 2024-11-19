#include <bits/stdc++.h>

using namespace std;

int A;
int B;
int C;
int tt[100];
int inTime;
int outTime;
int sum = 0;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> A;
    cin >> B;
    cin >> C;

    // map에 1~2 : 0 형태로 저장
    for (int i = 0; i < 3; i += 1) {
        cin >> inTime;
        cin >> outTime;
        for (int start = inTime; start < outTime; start += 1) {
            tt[start] += 1;
        }
    }
    for (int carAmount : tt) {
        if (carAmount == 1) {
            sum += A;
        }
        if (carAmount == 2) {
            sum += 2 * B;
        }
        if (carAmount == 3) {
            sum += 3 * C;
        }
    }
    cout << sum;

    return 0;
}
