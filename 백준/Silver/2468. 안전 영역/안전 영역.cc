#include <bits/stdc++.h>
using namespace std;

int N;                         // 지역 크기 (NxN)
int ground[100][100];          // 높이 정보
bool visited[100][100];        // 방문 여부
int maxComfortZoneCount = 0;   // 최대 안전 영역 개수

// 상하좌우 탐색 방향
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// DFS 함수: 연결된 영역 탐색
void DFS(int y, int x, int waterLevel) {
    visited[y][x] = true; // 현재 위치 방문 처리

    // 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 배열 경계 검사
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        // 물에 잠기지 않았고 아직 방문하지 않은 영역 탐색
        if (ground[ny][nx] > waterLevel && !visited[ny][nx]) {
            DFS(ny, nx, waterLevel);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력: 지역 크기 (N)
    cin >> N;

    int maximumHeight = 0; // 입력된 높이 중 최대값

    // 입력: 높이 정보
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ground[i][j];
            maximumHeight = max(maximumHeight, ground[i][j]);
        }
    }

    // 모든 물 높이에 대해 안전 영역 개수 계산
    for (int waterLevel = 0; waterLevel <= maximumHeight; waterLevel++) {
        // 방문 배열 초기화
        memset(visited, false, sizeof(visited));

        int comfortZoneCount = 0;

        // 모든 위치 탐색
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 물에 잠기지 않았고, 아직 방문하지 않은 영역에서 DFS 시작
                if (ground[i][j] > waterLevel && !visited[i][j]) {
                    DFS(i, j, waterLevel);
                    comfortZoneCount++; // 새로운 안전 영역 발견
                }
            }
        }

        // 최대 안전 영역 개수 갱신
        maxComfortZoneCount = max(maxComfortZoneCount, comfortZoneCount);
    }

    // 결과 출력: 최대 안전 영역 개수
    cout << maxComfortZoneCount << "\n";

    return 0;
}
