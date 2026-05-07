#include <iostream>
#include <queue>

using namespace std;
int r, c;
char map[24][24];
char map_visited[24][24];
int alphaVisited[26];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int result = 0;
void dfs(int y, int x, int dist) {
    result = max(dist, result);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0) continue;
        if (ny >= r || nx >= c) continue;
        if (alphaVisited[map[ny][nx] - 'A']) continue;
        if (map_visited[ny][nx]) continue;
        alphaVisited[map[ny][nx] - 'A'] = 1;
        map_visited[ny][nx] = 1;
        dfs(ny, nx, dist + 1);
        alphaVisited[map[ny][nx] - 'A'] = 0;
        map_visited[ny][nx] = 0;
    }
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    map_visited[0][0] = 1;
    alphaVisited[map[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << result;
    return 0;
}