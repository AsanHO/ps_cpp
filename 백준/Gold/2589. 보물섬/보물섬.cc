/*
서로 다른 육지중, 서로 가장 멀리 있는 곳에 보물이 있다.
이 두곳의 최단거리를 파악한다.

50,50
완전탐색으로 육지일때 탐색 시작,
이미 방문한경우 탐색 x이며 가장 긴 dist값이 나왔을때
result값 변경
*/

#include <iostream>
#include <queue>
using namespace std;
int N, M, result;
char ground[54][54];
int visited[54][54];
int dist[54][54];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
void BFS(int i, int j) {
    q.push({i, j});

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        visited[y][x] = 1;
        q.pop();
        if (dist[y][x] > result) {
            result = dist[y][x];
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N) continue;
            if (nx < 0 || nx >= M) continue;
            if (ground[ny][nx] == 'W') continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            dist[ny][nx] += dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ground[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ground[i][j] == 'L') {
                BFS(i, j);
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    dist[i][j] = 0;
                    visited[i][j] = 0;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}