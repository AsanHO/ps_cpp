#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// 1. 가장자리로 부터 시작한 0은 2로 변환 및 너우탐
// 2. 2가 0을 만나면 2로 변환
// 3. 1 상하좌우에 2가 있다면 0으로 반환
int N, M;
int ground[100][100] = {{0}};
int groundCopy[100][100];
bool groundVisited[100][100] = {{false}};
int resultHour = 0;
int resultCheezeCount = 0;
void DFS(int i, int j) {
    if (groundVisited[i][j] == true) return;
    groundVisited[i][j] = true;
    // if (ground[i][j] == 2) return;
    if (i > 0 && ground[i - 1][j] != 1) {
        ground[i - 1][j] = 2;
        DFS(i - 1, j);
    }
    // 우
    if (j < M - 1 && ground[i][j + 1] != 1) {
        ground[i][j + 1] = 2;
        DFS(i, j + 1);
    }
    // 하
    if (i < N - 1 && ground[i + 1][j] != 1) {
        ground[i + 1][j] = 2;
        DFS(i + 1, j);
    }
    // 좌
    if (j > 0 && ground[i][j - 1] != 1) {
        ground[i][j - 1] = 2;
        DFS(i, j - 1);
    }
}
int checkCheezeCount() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ground[i][j] == 1) count++;
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            ground[i][j] = num;
        }
    }

    DFS(0, 0);
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << ground[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while (checkCheezeCount() > 0) {
        int currentCheezCount = checkCheezeCount();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ground[i][j] == 1) {
                    if (ground[i - 1][j] == 2) {
                        ground[i][j] = 3;
                    } else if (ground[i][j + 1] == 2) {
                        ground[i][j] = 3;
                    } else if (ground[i + 1][j] == 2) {
                        ground[i][j] = 3;
                    } else if (ground[i][j - 1] == 2) {
                        ground[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ground[i][j] == 3) {
                    ground[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ground[i][j] == 0) {
                    if (ground[i - 1][j] == 2) {
                        DFS(i, j);
                    } else if (ground[i][j + 1] == 2) {
                        DFS(i, j);
                    } else if (ground[i + 1][j] == 2) {
                        DFS(i, j);
                    } else if (ground[i][j - 1] == 2) {
                        DFS(i, j);
                    }
                }
            }
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << ground[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        resultHour++;
        if (resultHour == 1 && checkCheezeCount() == 0) {
            resultCheezeCount = currentCheezCount;
            break;
        }
        if (checkCheezeCount() > 0) resultCheezeCount = checkCheezeCount();
        // cout << checkCheezeCount() << endl;
    }
    cout << resultHour << endl;
    cout << resultCheezeCount;

    return 0;
}