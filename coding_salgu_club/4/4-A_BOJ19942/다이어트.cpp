#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
int N;
int min_result = 2100000000;
int min_nutritions[4];
int nutritions[15][5];

// 현재까지 1인 아이템들의 영양합과 min_targets비교
vector<int> result;
int main() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> min_nutritions[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> nutritions[i][j];
        }
    }
    // 6인경우 1부터 63까지
    for (int mask = 1; mask < (1 << N); mask++) {
        int p = 0;
        int f = 0;
        int s = 0;
        int v = 0;
        int cost = 0;
        vector<int> temp;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {  // 켜져 있으면 추가
                p += nutritions[i][0];
                f += nutritions[i][1];
                s += nutritions[i][2];
                v += nutritions[i][3];
                cost += nutritions[i][4];
                temp.push_back(i);
            }
        }

        if (p >= min_nutritions[0] && f >= min_nutritions[1] && s >= min_nutritions[2] && v >= min_nutritions[3]) {
            if (min_result > cost) {
                min_result = cost;
                result = temp;
            }
        }
    }
    if (min_result == 2100000000) {
        cout << -1;
        return 0;
    }
    cout << min_result << "\n";
    for (int num : result) {
        cout << num + 1 << " ";
    }

    return 0;
}