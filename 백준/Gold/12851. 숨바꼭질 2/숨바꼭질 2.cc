/*
3개의 경우의 수를 BFS로 탐색하여 목표로 하는 지점의
최소 경로의 값을 찾고,
그 최소경로로 갈수 있는 방법의 개수까지 찾는다.

빈 배열 dist 을 만들고,
큐를 이용해 첫번째 위치부터 BFS를 시도한다.
이때 배열의 범위를 넘지 않도록 방어코드를 작성해야한다.
방법의 개수 , 중복되는 지점을 또한 탐색하기 위해서
dist와 똑같은 크기의 배열 cnt를 생성하고,
방문하지 않은 경우에는 dist와 cnt둘다 올려주고 탐색을 지속한다.
만약 이미 방문한 위치의 경우, 값이 -1이 아니므로 방문하기전
거리값과 비교하여 같은 경우,cnt값을 더해주고, 탐색을 종료한다.
BFS이므로 거리값과 비교했을때 원래 값보다 작을 일은 없다.
*/
#include <iostream>
#include <queue>

using namespace std;

int start;
int goal;
int dist[100004];
int cnt[100004];
int main() {
    cin >> start >> goal;
    // if (start == goal) {
    //     cout << 0 << endl;
    //     cout << 0 << endl;
    //     return 0;
    // }
    for (int i = 0; i <= 100000; i++) {
        dist[i] = -1;
    }
    dist[start] = 0;
    cnt[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int loc = q.front();
        q.pop();
        int nlocs[3] = {loc - 1, loc + 1, loc * 2};
        for (int nloc : nlocs) {
            if (nloc > 100000 || nloc < 0) continue;
            if (dist[nloc] == -1) {
                dist[nloc] = dist[loc] + 1;
                cnt[nloc] += cnt[loc];
                q.push(nloc);
            } else if (dist[nloc] == dist[loc] + 1) {
                cnt[nloc] += cnt[loc];
            }
        }
    }
    cout << dist[goal] << endl;
    cout << cnt[goal] << endl;
    return 0;
}