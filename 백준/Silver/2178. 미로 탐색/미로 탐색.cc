#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    vector<string> miro(n);
    int visited[n][m];

    queue<pair<int, int> > que;
    for (int i = 0; i < n; i++) {
        cin >> miro[i];  // 한 줄씩 입력받음
    }

    // 출력 확인 (문자 단위 접근 가능)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
            // cout << miro[i][j] << " ";  // 각 문자를 공백으로 구분하여 출력
        }
        // cout << "\n";
    }

    visited[0][0] = 1;

    que.push(make_pair(0, 0));
    int dy = 0;
    int dx = 0;
    while (que.size()) {
        pair<int, int> u = que.front();
        // cout << "현재위치" << u.first << "," << u.second << "\n";
        que.pop();
        if (u.first - 1 >= 0 && visited[u.first - 1][u.second] == 0 &&
            miro[u.first - 1][u.second] == '1') {
            // cout << "상";
            visited[u.first - 1][u.second] = visited[u.first][u.second] + 1;
            que.push(make_pair(u.first - 1, u.second));
        }
        if (u.first + 1 < n && visited[u.first + 1][u.second] == 0 &&
            miro[u.first + 1][u.second] == '1') {
            // cout << "하";
            visited[u.first + 1][u.second] = visited[u.first][u.second] + 1;
            que.push(make_pair(u.first + 1, u.second));
        }
        if (u.second - 1 >= 0 && visited[u.first][u.second - 1] == 0 &&
            miro[u.first][u.second - 1] == '1') {
            // cout << "좌";
            visited[u.first][u.second - 1] = visited[u.first][u.second] + 1;
            que.push(make_pair(u.first, u.second - 1));
        }
        if (u.second + 1 < m && visited[u.first][u.second + 1] == 0 &&
            miro[u.first][u.second + 1] == '1') {
            // cout << "우";
            visited[u.first][u.second + 1] = visited[u.first][u.second] + 1;
            que.push(make_pair(u.first, u.second + 1));
        }
    }
    cout << visited[n - 1][m - 1];
    return 0;
}
