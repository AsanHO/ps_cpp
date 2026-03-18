#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
이전과 동일하나, 홀짝을 구분해줘야 한다.
수빈 동생
5초 7초인경우
수빈이 왔다 갔다 해서 만날 수 있음.
*/
int N, K;
int visited[2][500004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    if (N == K) {
        cout << 0 << "\n";
        return 0;
    }
    queue<int> q;
    visited[0][N] = 1;
    q.push(N);
    int turn = 1;
    int ok = 0;
    while (q.size()) {
        K += turn;
        if (K > 500000) break;
        if (visited[turn % 2][K]) {
            ok = true;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int x = q.front();
            q.pop();
            for (int nx : {x + 1, x - 1, x * 2}) {
                if (nx < 0 || nx > 500000 || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if (nx == K) {
                    ok = 1;
                    break;
                }
                q.push(nx);
            }
            if (ok) break;
        }
        if (ok) break;
        turn++;
    }
    if (ok)
        cout << turn;
    else
        cout << -1;
    return 0;
}