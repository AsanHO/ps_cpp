#include <bits/stdc++.h>

using namespace std;
int n;
int m;
int result = 0;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    char floor[n][m];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            floor[i][j] = s[j];
        }
    }

    for (int q = 0; q < n; q++) {
        for (int w = 0; w < m; w++) {
            if (floor[q][w] == '-') {
                floor[q][w] = '0';
                int r = w + 1;
                while (true) {
                    if (floor[q][r] != '-' || r == m) {
                        break;
                    }
                    floor[q][r] = '0';
                    r += 1;
                }

                result += 1;
                // cout << "\n";
                // for (int a = 0; a < n; a++) {
                //     for (int s = 0; s < m; s++) {
                //         cout << floor[a][s];
                //     }
                //     cout << "\n";
                // }
                // cout << "결과" << "\n";
            }
            if (floor[q][w] == '|') {
                floor[q][w] = '0';
                int b = q + 1;
                while (true) {
                    if (floor[b][w] != '|' || b == n) {
                        break;
                    }
                    floor[b][w] = '0';
                    b += 1;
                }

                result += 1;
                // cout << "\n";
                // for (int a = 0; a < n; a++) {
                //     for (int s = 0; s < m; s++) {
                //         cout << floor[a][s];
                //     }
                //     cout << "\n";
                // }
                // cout << "결과" << "\n";
            }
        }
    }

    cout << result;
    return 0;
}
