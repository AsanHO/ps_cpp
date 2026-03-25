/*
1. L에서 탐색 시작
2. 실패하면 완전탐색으로 얼음 녹임
3. 1일 증가
4. 다시 탐색
5. 반복
ㄴ 시간 초과

효율화 위해서는 큐 두개 사용.
. 큐 현재 탐색중일때 #인경우 #큐에 넣고, .인 경우 방문 처리
큐 비어있으면 1일 추가
# 큐를 .큐로 전환

얼음을 녹이는 로직
스완을 탐색시키는 로직
BFS 총 두번 사용
*/
#include <iostream>
#include <queue>

using namespace std;
int R, C;
int startY, startX;
int endY, endX;
bool findFlag = false;
char map[1504][1504];
bool visited[1504][1504];
bool visited_swan[1504][1504];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int day = 0;

void print_map() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void print_visited() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'L') {
                if (!findFlag) {
                    startY = i;
                    startX = j;
                    findFlag = true;
                } else {
                    endY = i;
                    endX = j;
                }
            }
        }
    }

    queue<pair<int, int>> waterQ;
    queue<pair<int, int>> waterNQ;
    queue<pair<int, int>> swanQ;
    queue<pair<int, int>> swanNQ;
    swanQ.push({startY, startX});
    // cout << startY << startX << endl;
    visited[startY][startX] = 1;
    visited[endY][endX] = 1;
    visited_swan[startY][startX] = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != 'X') {
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    }
    while (true) {
        while (swanQ.size()) {
            int curY = swanQ.front().first;
            int curX = swanQ.front().second;
            swanQ.pop();
            // cout << curY << " " << curX << endl;
            for (int i = 0; i < 4; i++) {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];
                if (nextY < 0 || nextY >= R) continue;
                if (nextX < 0 || nextX >= C) continue;
                if (visited_swan[nextY][nextX] == 1) continue;
                visited_swan[nextY][nextX] = 1;
                if (map[nextY][nextX] == 'X') {
                    swanNQ.push({nextY, nextX});
                    continue;
                }
                // cout << "->" << nextY << " " << nextX << endl;
                if (map[nextY][nextX] == 'L') {
                    cout << day << endl;
                    return 0;
                }
                // visited_swan[nextY][nextX] = 1; 불필요한 탐색까지 진행함.
                swanQ.push({nextY, nextX});
            }
        }

        swanQ = swanNQ;
        queue<pair<int, int>> emptyQ;
        swanNQ = emptyQ;

        // cout << "백조 탐색 실패" << endl;
        while (waterQ.size()) {
            int curY = waterQ.front().first;
            int curX = waterQ.front().second;
            waterQ.pop();
            // cout << curY << " " << curX << endl;
            for (int i = 0; i < 4; i++) {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];
                if (nextY < 0 || nextY >= R) continue;
                if (nextX < 0 || nextX >= C) continue;
                if (visited[nextY][nextX] == 1) continue;
                // cout << "->" << nextY << " " << nextX << endl;
                if (map[nextY][nextX] == 'X') {
                    visited[nextY][nextX] = 1;
                    map[nextY][nextX] = '.';
                    waterNQ.push({nextY, nextX});
                    continue;
                }
                waterQ.push({nextY, nextX}); // 이미 경계선이므로 추가해줄필요가 없다.
            }
        }

        // while (waterNQ.size()) {
        //     int curY = waterNQ.front().first;
        //     int curX = waterNQ.front().second;
        //     map[curY][curX] = '.';
        //     waterQ.push(waterNQ.front());
        //     waterNQ.pop();
        // }
        waterQ = waterNQ;
        queue<pair<int, int>> emptyQ2;
        waterNQ = emptyQ2;
        // print_map();
        // cout << endl;
        // print_visited();
        // cout << endl;
        day++;
    }

    // cout << day << endl;
    return 0;
}
