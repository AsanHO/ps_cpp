#include <iostream>
#include <deque>
using namespace std;

int N, M;
int startX, startY, targetX, targetY;
char map[304][304];
int dist[304][304];

int main() {
    cin >> N >> M;
    cin >> startX >> startY >> targetX >> targetY;
    startX--; startY--;
    targetX--; targetY--;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dist[i][j] = -1;
        }
    }

    deque<pair<int,int>> dq;
    dq.push_front({startX, startY});
    dist[startX][startY] = 0;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;

            // 도착
            if (nx == targetX && ny == targetY) {
                cout << dist[x][y] + 1 << '\n';
                return 0;
            }

            if (map[nx][ny] == '0') {
                dist[nx][ny] = dist[x][y];
                dq.push_front({nx, ny}); // 핵심
            }
            else { // '1'
                dist[nx][ny] = dist[x][y] + 1;
                dq.push_back({nx, ny}); // 핵심
            }
        }
    }
}