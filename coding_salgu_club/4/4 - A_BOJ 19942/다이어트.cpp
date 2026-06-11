#include <algorithm>
#include <iostream>

using namespace std;
int N;
int min_targets[4];
int items[15][5];
int item_visited[15];
int min_result = 210000000;
void back_tracking() {}

void check_item() {
    for (int i = 0; i < N; i++) {
        if (!item_visited[i]) continue;
        for (int j = 0; j < 5; j++) {
        }
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
        back_tracking();
        item_visited[i] = 0;
    }

    return 0;
}