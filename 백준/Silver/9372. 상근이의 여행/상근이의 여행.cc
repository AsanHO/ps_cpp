#include <bits/stdc++.h>

using namespace std;
int t;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        int country, brand;
        cin >> country >> brand;
        for (int j = 0; j < brand; j++) {
            int a, b;
            cin >> a >> b;
        }
        cout << country - 1 << "\n";
    }

    return 0;
}
