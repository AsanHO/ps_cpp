#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int componentCount = 0;
int area;
vector<int> componentAreas;

// 육지는 1로 출력하자.
int ground[104][104];
bool visited[104][104];

void DFS(int y, int x) {
    visited[y][x] = 1;
    // cout << y << x << "방문완료" << "\n";
    area += 1;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (ground[ny][nx] == 1) continue;
        if (visited[ny][nx] == 1) continue;
        DFS(ny, nx);
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> M >> N >> K;

    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << ground[i][j];
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
    for (int i = 0; i < K; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int x = lx; x < rx; x++) {
            for (int y = ly; y < ry; y++) {
                ground[y][x] = 1;
            }
        }
    }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << ground[i][j];
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            area = 0;
            if (ground[i][j] == 0 && visited[i][j] == 0) {
                DFS(i, j);
                componentCount += 1;
                // cout << area << "\n";
                componentAreas.push_back(area);
            }
        }
    }

    sort(componentAreas.begin(), componentAreas.end());
    cout << componentCount << "\n";
    for (int area : componentAreas) {
        cout << area << " ";
    }

    return 0;
}
