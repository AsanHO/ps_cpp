#include <bits/stdc++.h>

using namespace std;

int N, M;
int nums[100004], psum[100004];
int start, finish;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    for (int i = 1; i < N + 1; i += 1) {
        cin >> nums[i];
        psum[i] = psum[i - 1] + nums[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> start;
        cin >> finish;
        cout << psum[finish] - psum[start - 1] << "\n";
    }

    return 0;
}
