#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N, L, R;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[54][54] = {
    0,
};
bool mapFlags[54][54] = {
    false,
};
bool isChange = false;
int day = 0;
// BFS로 섹션 확인
// 이미 탐색완료 한 경우(플래그값 확인) 스킵
// 섹션들의 값 계산
// 하루 지나고 플래그값 초기화
// 탐색 이후 변화가 없다면 종료

void BFS(int si, int sj) {
    if (mapFlags[si][sj]) return;
    queue<pair<int, int>> q;
    vector<pair<int, int>> section;

    q.push({si, sj});
    mapFlags[si][sj] = true;
    section.push_back({si, sj});

    int sum = map[si][sj];

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int p = 0; p < 4; p++) {
            int nx = x + dx[p];
            int ny = y + dy[p];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (mapFlags[nx][ny]) continue;

            int diff = abs(map[x][y] - map[nx][ny]);
            if (diff < L || diff > R) continue;

            mapFlags[nx][ny] = true;
            isChange = true;
            q.push({nx, ny});
            section.push_back({nx, ny});
            sum += map[nx][ny];
        }
    }

    int newNum = sum / section.size();
    for (auto s : section) {
        // cout << s.first << " " << s.second << endl;
        map[s.first][s.second] = newNum;
    }
}
vector<pair<int, int>> openCountries;
int main() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // cout << map[i][j] << " : " << mapFlags[i][j] << " , ";
        }
        // cout << endl;
    }

    while (true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                BFS(i, j);
            }
        }
        if (!isChange) {
            break;
        }
        isChange = false;
        day++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mapFlags[i][j] = false;
            }
        }
        }

    cout << day << endl;
    return 0;
}
