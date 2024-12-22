#include <bits/stdc++.h>

using namespace std;
int today[1004][1004];
int afterToday[1004][1004];
int answer = 0;
bool isChanged = false;
vector<pair<int, int> > targets;
vector<pair<int, int> > nextTargets;
int a, b;
bool detectContainsZero() {
    // cout << "켜지긴함?";
    for (int y = 0; y < a; y++) {
        for (int x = 0; x < b; x++) {
            // cout << "0인가 - >" << today[y][x] << "\n";
            if (today[y][x] == 0) return true;
        }
    }
    return false;
}
void grow(int y, int x) {
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= a || nx < 0 || nx >= b) continue;
        if (today[ny][nx] == -1 || today[ny][nx] == 1 || today[ny][nx] == 2)
            continue;
        today[ny][nx] = 1;
        nextTargets.push_back(make_pair(ny, nx));
        isChanged = true;
    }
    // for (int i = 0; i < a; ++i) {
    //     for (int j = 0; j < b; ++j) {
    //         cout << today[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
int main() {
    cin >> b >> a;
    int answer = 0;

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cin >> today[i][j];
            // cout << today[i][j] << " ";
            if (today[i][j] == 1) {
                // cout << y << x << "여기서 검사시작";
                // cout << "\n";
                targets.push_back(make_pair(i, j));
                // for (int i = 0; i < a; ++i) {
                //     for (int j = 0; j < b; ++j) {
                //         cout << today[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
            }
        }
        // cout << "\n";
    }

    while (true) {
        isChanged = false;
        for (pair<int, int> target : targets) {
            // cout << target.first << target.second << "\n";
            grow(target.first, target.second);
            today[target.first][target.second] = 2;
            // for (int i = 0; i < a; ++i) {
            //     for (int j = 0; j < b; ++j) {
            //         cout << today[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
        }
        if (!isChanged) break;
        targets = nextTargets;
        nextTargets.clear();
        answer += 1;
        // cout << answer << "일차" << "\n";
    }

    // 0이 있는지 검사
    if (detectContainsZero()) answer = -1;
    cout << answer;

    return 0;
}
