#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long fir, sec;
    if (a > b) {
        sec = a;
        fir = b;
    } else if (a < b) {
        fir = a;
        sec = b;
    } else {
        cout << 0;
        return 0;
    }

    cout << sec - fir - 1 << "\n";
    for (long long i = fir + 1; i < sec; i++) {
        cout << i;
        if (i != sec - 1) {
            cout << " ";
        }
    }

    return 0;
}