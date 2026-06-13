#include <algorithm>
#include <iostream>
/*
6
100 70 90 10
30 55 10 8 100
60 10 10 2 70
10 80 50 0 50
40 30 30 8 60
60 10 70 2 120
20 70 50 4 4
*/
using namespace std;
int N;
int min_targets[4];
int items[15][5];
int item_visited[15];
int min_result = 2100000000;
int final_items[15];

// 현재까지 1인 아이템들의 영양합과 min_targets비교
void check_item() {
    int sum[5] = {0};
    for (int i = 0; i < N; i++) {
        if (!item_visited[i]) continue;
        for (int j = 0; j < 5; j++) {
            sum[j] += items[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (min_targets[i] > sum[i]) {
            return;
        }
    }
    if (min_result > sum[4]) {
        min_result = sum[4];
        for (int i = 0; i < N; i++) {
            if (item_visited[i]) {
                final_items[i] = 1;
            } else {
                final_items[i] = 0;
            }
        }
    }
}
void back_tracking(int cur) {
    for (int i = 0; i < N; i++) {
        if (item_visited[i]) continue;
        item_visited[i] = 1;
        check_item();
        back_tracking(i);
        item_visited[i] = 0;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> min_targets[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> items[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        item_visited[i] = 1;
        check_item();
        back_tracking(i);
        item_visited[i] = 0;
    }
    if (min_result == 2100000000) {
        cout << -1;
        return 0;
    }
    cout << min_result << endl;
    for (int i = 0; i < N; i++) {
        if (final_items[i]) cout << i + 1 << " ";
    }
    return 0;
}