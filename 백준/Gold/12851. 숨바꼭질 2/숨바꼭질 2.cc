#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100001];
int cnt[100001];

int main() {
    cin >> N >> K;

    for (int i = 0; i <= 100000; i++) dist[i] = -1;

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    cnt[N] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int nexts[3] = {cur - 1, cur + 1, cur * 2};

        for (int next : nexts) {
            if (next < 0 || next > 100000) continue;
            if (dist[next] == -1) {  // 방문안했다면
                dist[next] = dist[cur] + 1;
                cnt[next] = cnt[cur];
                q.push(next);
            } else if (dist[next] == dist[cur] + 1) {  // 방문했는데 최단거리(중복)인경우
                cnt[next] += cnt[cur];
            }
        }
    }

    cout << dist[K] << "\n";
    cout << cnt[K] << "\n";
}