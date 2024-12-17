// 연결 컴포넌트 문제 -> DFS
#include <bits/stdc++.h>

using namespace std;
int t, m, n, k;

int ground[51][51];
bool visited[51][51];

pair<int, int> ds[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1),
                        make_pair(0, 1)};
void DFS(int dy, int dx) {
    // cout << "\n" << dy << dx << "탐색시작";
    if (visited[dy][dx] || ground[dy][dx] == 0) return;
    visited[dy][dx] = true;
    // cout << "\n" << dy << dx << "탐색완료";
    for (pair<int, int> d : ds) {
        int ny, nx;
        ny = dy + d.first;
        nx = dx + d.second;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || ground[ny][nx] == 0) continue;
        // cout << ny << nx << "로 이동" << "\n";
        DFS(ny, nx);
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        // cout << "세로길이:" << n << "\n";
        // cout << "가로길이:" << m << "\n";
        int conectedComponentsCount = 0;
        fill(&ground[0][0], &ground[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ground[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < k; i++) {
            int dy, dx;
            cin >> dy >> dx;
            ground[dy][dx] = 1;
        }
        // cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << ground[i][j] << " ";
            }
            // cout << "\n";
        }
        // cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << visited[i][j] << " ";
            }
            // cout << "\n";
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || ground[i][j] == 0) continue;
                // cout << i << j << "에서 지렁이 탐색";
                DFS(i, j);
                conectedComponentsCount += 1;
                // cout << "\n";
                // cout << "컴포넌트 수: " << conectedComponentsCount;
                // cout << "\n";
            }
            // cout << "\n";
        }
        cout << conectedComponentsCount << "\n";
    }

    return 0;
}
