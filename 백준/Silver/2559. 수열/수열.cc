#include <bits/stdc++.h>

using namespace std;

int N;
int K;
int maxNum = -100000;

int main(int argc, char const *argv[]) {
    cin >> N;
    cin >> K;
    int temps[N];
    for (int i = 0; i < N; i += 1) {
        cin >> temps[i];
    }
    for (int j = 0; j < N - K + 1; j += 1) {
        int sum = temps[j];
        for (int k = 1; k < K; k += 1) {
            sum += temps[j + k];
        }
        if (sum > maxNum) {
            maxNum = sum;
        }
    }
    cout << maxNum;

    return 0;
}
