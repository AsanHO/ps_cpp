/*
 백트래킹 문제
 검사함수를 만들고,
 사다리 조건을 만족할때 마다
 검사함수 통과
 이후 결과값 비교후 최솟값 저장

 가로선은 서로 연속하지 않음

 1이면 오른쪽으로 이동,
 왼쪽이 1이면 왼쪽으로 이동
*/

#include <algorithm>
#include <iostream>

using namespace std;
int sadari[10][30];
int N, H, M;
int result = 4;
void print_sadari() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            cout << sadari[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool check_sadari() {
    // print_sadari();
    for (int i = 0; i < N; i++) {
        int target = i;
        // cout << i << "탐색 시작" << endl;
        for (int j = 0; j < H; j++) {
            if (sadari[j][i]) {
                // cout << i << " " << N - 1 << endl;
                i++;
                // cout << "가로선 발견 " << i << " 로 이동" << endl;
            } else if (i > 0 && sadari[j][i - 1]) {
                i--;
            }
        }
        if (target != i) {
            // cout << target << " 이 " << i << " 에 도달" << endl;
            return false;
        }
        // cout << "이상무" << endl;
    }
    return true;
}
void dfs_backtracking(int r, int c, int cur_add) {
    // cout << r << c << "에 사다리 추가 " << endl;
    if (cur_add > 3) return;
    if (check_sadari()) {
        result = min(result, cur_add);
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (sadari[i][j] == 1) continue;
            if (sadari[i][j - 1] == 1) continue;
            if (sadari[i][j + 1] == 1) continue;
            sadari[i][j] = 1;
            dfs_backtracking(i, j, cur_add + 1);
            sadari[i][j] = 0;
        }
    }
}
int main() {
    cin >> N >> M >> H;
    // 검사한번 하기
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        sadari[start][end] = 1;
    }

    if (check_sadari()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            if (sadari[i][j] == 1) continue;
            if (sadari[i][j - 1] == 1) continue;
            if (sadari[i][j + 1] == 1) continue;

            sadari[i][j] = 1;
            dfs_backtracking(i, j, 1);
            sadari[i][j] = 0;
        }
    }
    result = result > 3 ? -1 : result;
    cout << result;
    return 0;
}