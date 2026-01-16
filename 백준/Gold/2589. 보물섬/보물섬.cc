#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char world[50][50];
int dist[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> world[i][j];

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (world[i][j] != 'L') continue;

            memset(dist, -1, sizeof(dist));
            queue<pair<int,int>> q;

            dist[i][j] = 0;
            q.push({i, j});

            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                int x = cur.first;
                int y = cur.second;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                        continue;
                    if (world[nx][ny] != 'L')
                        continue;
                    if (dist[nx][ny] != -1)
                        continue;

                    dist[nx][ny] = dist[x][y] + 1;
                    answer = max(answer, dist[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}
