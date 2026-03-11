#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
12 10 4
1 3 2

3 9 1
2 1 3

0 0 0

*/
int scv_count;
const int INF = 987654321;
int dp[64][64][64] = {};
int visited[64][64][64];
int scvs[3] = {
    0,
};
int n;
// 이정도 경우의 수는 그냥 배열로 만들자.
int _a[6][3] = {
    {9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3},
};
struct A {
    int a, b, c;
};
queue<A> q;
/*
BFS로 풀어야 하는 이유
- 가중치가 같은 그래프
- 18, 5 ,2 의 가중치를 갖고 있는 한개의 정점
- 이 정점은 6가지의 경로가 있다. (기본 문제에서는 상하좌우 4개)
- 우리의 목표는 0,0,0이 되는 정점.
*/
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size()) {
        A pick = q.front();
        int a = pick.a;
        int b = pick.b;
        int c = pick.c;
        // cout << a << " " << b << " " << c << endl;
        q.pop();
        if (visited[0][0][0]) break;
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            // cout << na << " " << nb << " " << nc << " -> ";
            if (visited[na][nb][nc]) continue;
            if (dp[na][nb][nc] != INF) continue;
            q.push({na, nb, nc});
            dp[na][nb][nc] = dp[a][b][c] + 1;
            // cout << dp[na][nb][nc] << endl;
            if (na == 0 && nb == 0 && nc == 0) {
                return dp[na][nb][nc];
            }
        }
    }
}
int main() {
    cin >> scv_count;
    for (int i = 0; i < scv_count; i++) {
        cin >> scvs[i];
    }
    fill(&dp[0][0][0], &dp[0][0][0] + 64 * 64 * 64, 987654321);
    dp[scvs[0]][scvs[1]][scvs[2]] = 0;
    cout << solve(scvs[0], scvs[1], scvs[2]);
    // cout << dp[0][0][0] - 1 << endl;
    return 0;
}
