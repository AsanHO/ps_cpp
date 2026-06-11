#include <iostream>
using namespace std;
int R, C, K;
int map[5][5];
int result = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void print_map() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void dfs_backtracking(int y, int x, int count) {
    // print_map();
    if (y == 0 && x == C - 1) {
        if (count == K) {
            result++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0) continue;
        if (ny >= R || nx >= C) continue;
        if (map[ny][nx] == -1) continue;
        if (map[ny][nx]) continue;
        map[ny][nx] = 1;
        dfs_backtracking(ny, nx, count + 1);
        map[ny][nx] = 0;
    }
}
int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            if (c == 'T') {
                map[i][j] = -1;
            }
        }
    }
    map[R - 1][0] = 1;
    dfs_backtracking(R - 1, 0, 1);
    cout << result << endl;
    return 0;
}