#include <bits/stdc++.h>

using namespace std;

int N;
int image[64][64];
string answer = "";

void print(vector<int> v) {
    for (auto i : v) {
        cout << i;
    }
    cout << '\n';
}

int checkClean(int sy, int sx, int fy, int fx) {
    int init = image[sy][sx];
    // cout << sy << "," << sx << "부터" << fy << "," << fx << "까지 검사\n";
    for (int y = sy; y < fy; y++) {
        for (int x = sx; x < fx; x++) {
            // cout << image[y][x];
        }
        // cout << "\n";
    }
    for (int y = sy; y < fy; y++) {
        for (int x = sx; x < fx; x++) {
            if (init != image[y][x]) return -1;
        }
    }
    return init;
}

void press(int sy, int sx, int fy, int fx) {
    int checkResult = checkClean(sy, sx, fy, fx);
    if (checkResult != -1) {
        answer += checkResult + '0';
        return;
    }
    if (fy - sy <= 2) {
        answer += "(";
        answer += image[sy][sx] + '0';
        answer += image[sy][fx - 1] + '0';
        answer += image[fy - 1][sx] + '0';
        answer += image[fy - 1][fx - 1] + '0';
        answer += ")";
        return;
    }
    answer += "(";
    //(0448)
    // cout << "1압축\n";
    press(sy, sx, (fy + sy) / 2, (fx + sx) / 2);  // (0,4,2,4)
    // cout << "2압축\n";
    press(sy, (fx + sx) / 2, (fy + sy) / 2, fx);  // (0,2,4,8)
    // cout << "3압축\n";
    press((fy + sy) / 2, sx, fy, (fx + sx) / 2);  // (4,0,8,4)
    // cout << "4압축\n";
    press((fy + sy) / 2, (fx + sx) / 2, fy, fx);  // (4,4,8,8)
    answer += ")";
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            image[i][j] = row[j] - '0';
        }
    }
    //
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << image[i][j];
    //     }
    //     cout << "\n";
    // }
    //
    press(0, 0, N, N);
    cout << answer;
    return 0;
}
