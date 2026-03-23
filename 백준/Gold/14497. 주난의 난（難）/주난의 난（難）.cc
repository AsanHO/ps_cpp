/*
첫째 줄에 주난이가 위치한 교실의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 300)

둘째 줄에 주난이의 위치 startX, startY과 범인의 위치 targetX, y2가 주어진다. (1 ≤ startX, targetX ≤ N, 1 ≤ startY, targetY ≤ M)

이후 N×M 크기의 교실 정보가 주어진다. 0은 빈 공간, 1은 친구, *는 주난, #는 범인을 뜻한다.

0-1BFS를 통해 푸는 문제

0-1BFS 이란, 한칸씩 가는 탐색과 달리 갈수 있는 위치라면 전부 탐색을 시도하는 기법
- 큐를 두개쓰거나
- 덱 사용

파동은 상하좌우로 움직이며 0에서부터 출발

주난의 위치로부터 상하좌우 움직이게 되며 파동은 0에도 전달된다.
1을 발견했을 시, 0으로 바꿔주고 dist에 이전노드+1을 넣어주고 큐에 삽입, cnt증가
0을 발견했을 시, dist는 이전노드와 동일하며 제로큐에 삽입
사용하는 자료구조는 총 세개
큐
맵과
dist(visited로도 사용)
이미 방문한 곳은 dist업데이트 안함

1#11111
1101001
001*111
1101111
0011001

--2222-
2221222
221012-
22212--
--2222-
*/

#include <iostream>
#include <queue>

using namespace std;
int N, M;
int startX, startY, targetX, targetY;
char map[304][304];
int dist[304][304];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void printDist() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1)
                cout << '-';
            else
                cout << dist[i][j];
        }
        cout << endl;
    }
}
int main() {
    cin >> N >> M;
    cin >> startX >> startY >> targetX >> targetY;
    startX -= 1;
    startY -= 1;
    targetX -= 1;
    targetY -= 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < 304; i++) {
        for (int j = 0; j < 304; j++) {
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> zeroq;
    dist[startX][startY] = 0;
    q.push({startX, startY});
    while (q.size()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (nextX < 0 || nextX >= N) continue;
            if (nextY < 0 || nextY >= M) continue;
            if (dist[nextX][nextY] != -1) continue;

            // 0이면 제로큐에 넣기
            if (map[nextX][nextY] == '0') {
                dist[nextX][nextY] = dist[curX][curY];
                zeroq.push({nextX, nextY});
            }
            // 1이면 map에 표시, 큐에 넣기
            if (map[nextX][nextY] == '1') {
                map[nextX][nextY] = '0';
                dist[nextX][nextY] = dist[curX][curY] + 1;
                q.push({nextX, nextY});
            }
            if (map[nextX][nextY] == '#') {
                map[nextX][nextY] = '0';
                dist[nextX][nextY] = dist[curX][curY] + 1;
                cout << dist[nextX][nextY];
                return 0;
            }
        }

        while (zeroq.size()) {
            int curX = zeroq.front().first;
            int curY = zeroq.front().second;
            zeroq.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if (nextX < 0 || nextX >= N) continue;
                if (nextY < 0 || nextY >= M) continue;
                if (dist[nextX][nextY] != -1) continue;
                // 0이면 제로큐에 넣기
                if (map[nextX][nextY] == '0') {
                    dist[nextX][nextY] = dist[curX][curY];
                    zeroq.push({nextX, nextY});
                }
                // 1이면 map에 표시, 큐에 넣기
                if (map[nextX][nextY] == '1') {
                    map[nextX][nextY] = '0';
                    dist[nextX][nextY] = dist[curX][curY] + 1;
                    q.push({nextX, nextY});
                }
                if (map[nextX][nextY] == '#') {
                    map[nextX][nextY] = '0';
                    dist[nextX][nextY] = dist[curX][curY] + 1;
                    cout << dist[nextX][nextY];
                    return 0;
                }
            }
        }
        // printDist();
    }
    cout << "끝!" << dist[targetX][targetY] << endl;
    return 0;
}
