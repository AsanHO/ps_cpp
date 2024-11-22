#include <bits/stdc++.h>

using namespace std;

int T;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        map<string, int> clothes;
        set<string> types;
        for (int j = 0; j < N; j++) {
            string name;
            string type;

            cin >> name;
            cin >> type;

            clothes[type] += 1;
            types.insert(type);
        }
        int result = 1;
        for (string i : types) {
            result *= clothes[i] + 1;
        }
        cout << result - 1 << "\n";
    }

    return 0;
}
