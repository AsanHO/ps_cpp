/*
1500 * 1500이므로 효율적인 탐색이 필요하다.

큐는 총 4개
물을 녹이는데 필요한 큐 두개
백조 이동용 큐 두개
두개인 이유는 이후에 방문할 큐를 만들기 위해
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int R, C;
char map[1504][1504];
bool visited[1504][1504];
bool visited_swan[1504][1504];
int startY, startX;
bool findFlag = false;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int day = 0;
queue<pair<int, int>> swanq, swannq;
queue<pair<int, int>> waterq, waternq;

void printMap() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printVisit() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printVisitSwan() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << visited_swan[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void waterMelt() {
    while (waterq.size()) {
        int curY = waterq.front().first;
        int curX = waterq.front().second;
        waterq.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R) continue;
            if (nextX < 0 || nextX >= C) continue;
            if (visited[nextY][nextX]) continue;

            if (map[nextY][nextX] == 'X') {
                visited[nextY][nextX] = 1;
                map[nextY][nextX] = '.';
                waternq.push({nextY, nextX});
            }
        }
    }
}
bool swanMove() {
    while (swanq.size()) {
        int curY = swanq.front().first;
        int curX = swanq.front().second;
        swanq.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R) continue;
            if (nextX < 0 || nextX >= C) continue;
            if (visited_swan[nextY][nextX]) continue;
            visited_swan[nextY][nextX] = 1;
            if (map[nextY][nextX] == 'X') {
                swannq.push({nextY, nextX});
                continue;
            }
            if (map[nextY][nextX] == 'L') {
                return true;
            }
            swanq.push({nextY, nextX});
        }
    }
    return false;
}
void clearQ(queue<pair<int, int>>& q) {
    queue<pair<int, int>> newq;
    swap(q, newq);
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] != 'X') {
                visited[i][j] = 1;
                waterq.push({i, j});
            }
            if (map[i][j] == 'L' && !findFlag) {
                startY = i;
                startX = j;
                findFlag = true;
            }
        }
    }
    swanq.push({startY, startX});
    visited_swan[startY][startX] = 1;

    while (true) {
        if (swanMove()) break;
        waterMelt();
        swanq = swannq;
        waterq = waternq;
        clearQ(swannq);
        clearQ(waternq);
        day++;
        // printMap();
        // printVisit();
        // printVisitSwan();
    }
    cout << day << endl;
    return 0;
}