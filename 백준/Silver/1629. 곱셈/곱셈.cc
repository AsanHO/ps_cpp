#include <bits/stdc++.h>

using namespace std;

long long A, B, C;

long long cal(long long a, long long b) {
    if (b == 1) return a % C;
    long long ret = cal(a, b / 2);
    ret = (ret * ret) % C;
    if (b % 2 != 0) {
        ret = (ret * a) % C;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> A >> B >> C;

    cout << cal(A, B);

    return 0;
}
