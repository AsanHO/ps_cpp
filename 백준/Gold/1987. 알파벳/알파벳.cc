/*
백트래킹 BFS
돌아서 가는 방법이 최대 거리가 나오는데
일반 적인 BFS로는 경로를 탐색할 수 없음
최대한 많은 경로를 탐색해서
가장 거리가 긴걸 탐색해야한다.
재귀함수 호출 후, 최댓값 비교
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int R, C;
int sy, sx;
char map[21][21];
int visited[27];  // char을 int형으로 변환해서 사용
int result;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void BFS_backtracking(int y, int x, int num) {
    result = max(num, result);
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || ny >= R) continue;
        if (nx < 0 || nx >= C) continue;
        if (visited[map[ny][nx] - 'A']) continue;
        visited[map[ny][nx] - 'A'] = 1;
        BFS_backtracking(ny, nx, num + 1);
        visited[map[ny][nx] - 'A'] = 0;
    }
};
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    visited[map[0][0] - 'A'] = 1;
    BFS_backtracking(0, 0, 1);
    cout << result;
    return 0;
}
