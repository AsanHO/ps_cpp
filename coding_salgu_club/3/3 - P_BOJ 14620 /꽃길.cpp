#include <algorithm>
#include <iostream>
/*
씨앗은 단 세개!
*/
using namespace std;
int N;

int price_map[12][12];
int flower_map[12][12];
int min_result = 200 * 10 * 10;
void print_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << flower_map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void dfs_backtracking(int y, int x, int count) {
    if (count == 3) {
        // todo 검사
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (flower_map[i][j]) {
                    result += price_map[i][j];
                }
            }
        }
        min_result = min(min_result, result);

        return;
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (flower_map[i][j]) continue;
            if (flower_map[i - 1][j]) continue;
            if (flower_map[i + 1][j]) continue;
            if (flower_map[i][j - 1]) continue;
            if (flower_map[i][j + 1]) continue;
            flower_map[i][j] = 1;
            flower_map[i - 1][j] = 1;
            flower_map[i + 1][j] = 1;
            flower_map[i][j - 1] = 1;
            flower_map[i][j + 1] = 1;
            dfs_backtracking(i, j, count + 1);
            flower_map[i][j] = 0;
            flower_map[i - 1][j] = 0;
            flower_map[i + 1][j] = 0;
            flower_map[i][j - 1] = 0;
            flower_map[i][j + 1] = 0;
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> price_map[i][j];
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            flower_map[i][j] = 1;
            flower_map[i - 1][j] = 1;
            flower_map[i + 1][j] = 1;
            flower_map[i][j - 1] = 1;
            flower_map[i][j + 1] = 1;
            dfs_backtracking(i, j, 1);
            flower_map[i][j] = 0;
            flower_map[i - 1][j] = 0;
            flower_map[i + 1][j] = 0;
            flower_map[i][j - 1] = 0;
            flower_map[i][j + 1] = 0;
        }
    }
    cout << min_result << endl;
    return 0;
}