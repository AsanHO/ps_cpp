#include <bits/stdc++.h>

using namespace std;

int N;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    while (cin >> N) {  // 입력이 더 이상 주어지지 않을 때 종료
        long long target = 1;
        int count = 1;
        while (true) {
            if (target % N == 0) {  // 11의
                cout << count << "\n";
                break;
            }
            string add = to_string(target) + "1";
            target = stoll(add) % N;
            count += 1;
        }
    }

    return 0;
}
