#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int dist[100001];
int parent[100001];

int main() {
    cin >> N >> K;

    for (int i = 0; i <= 100000; i++) dist[i] = -1;

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    parent[N] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int nexts[3] = {cur - 1, cur + 1, cur * 2};

        for (int next : nexts) {
            if (next < 0 || next > 100000) continue;

            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                parent[next] = cur;
                q.push(next);
            }
        }
    }

    vector<int> result;

    int cur = K;
    while (cur != -1) {
        result.push_back(cur);
        cur = parent[cur];
    }

    reverse(result.begin(), result.end());

    cout << dist[K] << "\n";

    for (auto m : result) cout << m << " ";
}