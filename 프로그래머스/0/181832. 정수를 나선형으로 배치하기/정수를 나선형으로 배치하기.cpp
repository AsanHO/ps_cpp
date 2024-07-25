#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int index = 1;
    int limit = 1;
    int column = 0;
    int depth = n - 1;

    // 좌 -> 우
    while (index <= n * n) {
        for (int i = 0; i < n; i++) {
            // cout << column << i << endl;
            int value = answer[column][i];
            // cout << value << endl;
            if (value == 0) {
                answer[column][i] = index;
                index += 1;
            }
        }
        // 상 -> 하
        for (int i = 0; i < n; i++) {
            // cout << depth << i << endl;
            int value = answer[i][depth];
            // cout << value << endl;
            if (value == 0) {
                answer[i][depth] = index;
                index += 1;
            }
        }
        // 우 -> 좌
        for (int i = n - 1; i >= 0; i--) {
            // cout << depth << i << endl;
            int value = answer[depth][i];
            // cout << value << endl;
            if (value == 0) {
                answer[depth][i] = index;
                index += 1;
            }
        }
        // 하 -> 상
        for (int i = n - 1; i >= 0; i--) {
            // cout << i << column << endl;
            int value = answer[i][column];
            // cout << value << endl;
            if (value == 0) {
                answer[i][column] = index;
                index += 1;
            }
        }
        column += 1;
        depth -= 1;
    }
    
    return answer;
}