#include <algorithm>
#include <iostream>

using namespace std;

int n;
char map[20][20];
int visited_map[40];
int result = 2100000000;

void print_map() {
    for (int i = 0; i < n * 2; i++) {
        cout << visited_map[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void checkT() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'T') sum++;
        }
    }
    result = min(result, sum);
}

void flip(int flag, bool isCol) {
    if (isCol) {
        for (int i = 0; i < n; i++) {
            map[flag][i] = map[flag][i] == 'H' ? 'T' : 'H';
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        map[i][flag] = map[i][flag] == 'H' ? 'T' : 'H';
    }
}

void bt(int cur) {  // 순열이므로 cur은 필요없음
    for (int i = 0; i < n * 2; i++) {
        if (visited_map[i]) continue;
        visited_map[i] = 1;
        bool isCol = i < n ? true : false;
        flip(i % n, isCol);
        // print_map();
        checkT();
        bt(i);
        flip(i % n, isCol);
        visited_map[i] = 0;
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    // print_map();
    checkT();
    for (int i = 0; i < n * 2; i++) {
        visited_map[i] = 1;
        bool isCol = i < n ? true : false;
        flip(i % n, isCol);
        checkT();
        // print_map();
        bt(i);
        flip(i % n, isCol);
        visited_map[i] = 0;
    }
    cout << result;
    return 0;
}