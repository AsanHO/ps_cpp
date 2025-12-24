#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// 브루트포스 => 빈 좌표값의 2차원값을 1차원값으로 변환한뒤 경우의 수를 모두 계산
vector<pair<int, int>> safeZones;
int maxSafeZoneCount = 0;
int N, M;
// void incomeVirus() {}
// int getSafeZoneCount() {}
int ground[8][8] = {{0}};
int groundCopy[8][8];
bool groundCopyVisited[8][8] = {{false}};

void DFS(int i, int j) {
    if (groundCopyVisited[i][j] == true) return;
    groundCopyVisited[i][j] = true;
    if (groundCopy[i][j] != 2) return;
    if (i > 0 && groundCopy[i - 1][j] != 1) {
        groundCopy[i - 1][j] = 2;
        DFS(i - 1, j);
    }
    // 우
    if (j < M - 1 && groundCopy[i][j + 1] != 1) {
        groundCopy[i][j + 1] = 2;
        DFS(i, j + 1);
    }
    // 하
    if (i < N - 1 && groundCopy[i + 1][j] != 1) {
        groundCopy[i + 1][j] = 2;
        DFS(i + 1, j);
    }
    // 좌
    if (j > 0 && groundCopy[i][j - 1] != 1) {
        groundCopy[i][j - 1] = 2;
        DFS(i, j - 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            ground[i][j] = num;
            if (num == 0) {
                safeZones.push_back(make_pair(i, j));
            }
            // cout << ground[i][j] << " ";
        }
        // cout << endl;
    }

    memcpy(groundCopy, ground, sizeof(ground));
    for (pair<int, int> sz1 : safeZones) {
        for (pair<int, int> sz2 : safeZones) {
            for (pair<int, int> sz3 : safeZones) {
                if (sz1 == sz2 || sz2 == sz3 || sz1 == sz3) continue;
                if (groundCopy[sz1.first][sz1.second] == 1 || groundCopy[sz2.first][sz2.second] == 1 || groundCopy[sz3.first][sz3.second] == 1) continue;

                groundCopy[sz1.first][sz1.second] = 1;
                groundCopy[sz2.first][sz2.second] = 1;
                groundCopy[sz3.first][sz3.second] = 1;
                // for (int i = 0; i < N; i++) {
                //     for (int j = 0; j < M; j++) {
                //         cout << groundCopy[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (groundCopy[i][j] == 2) {
                            DFS(i, j);
                            // if (i > 0 && groundCopy[i - 1][j] != 1) {
                            //     groundCopy[i - 1][j] = 2;
                            // }
                            // // 우
                            // if (j < N - 1 && groundCopy[i][j + 1] != 1) {
                            //     groundCopy[i][j + 1] = 2;
                            // }
                            // // 하
                            // if (i < M - 1 && groundCopy[i + 1][j] != 1) {
                            //     groundCopy[i + 1][j] = 2;
                            // }
                            // // 좌
                            // if (j > 0 && groundCopy[i][j + 1] != 1) {
                            //     groundCopy[i][j + 1] = 2;
                            // }
                        }
                    }
                }
                // for (int i = 0; i < N; i++) {
                //     for (int j = 0; j < M; j++) {
                //         cout << groundCopy[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                int safeZoneCount = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (groundCopy[i][j] == 0) {
                            safeZoneCount++;
                        }
                    }
                }

                if (maxSafeZoneCount < safeZoneCount) {
                    maxSafeZoneCount = safeZoneCount;
                    // cout << safeZoneCount << endl;
                }
                memcpy(groundCopy, ground, sizeof(ground));  // 초기화
                memset(groundCopyVisited, false, sizeof(groundCopyVisited));
            }
        }
    }
    cout << maxSafeZoneCount;
    return 0;
}