#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<string> names;
vector<char> fChar;
string result;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> cnt;
    // 삽입
    for (int i = 0; i < cnt; i++) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    // 순회
    for (string name : names) {
        char fName = name[0];
        if (find(fChar.begin(), fChar.end(), fName) == fChar.end()) {
            fChar.push_back(fName);
            int count = 0;
            for (string name : names) {
                if (fName == name[0]) {
                    count += 1;
                }
                if (count == 5) {
                                        result += fName;
                    break;
                }
            }
        }
    }
    if (result == "") {
        cout << "PREDAJA";
    }
    sort(result.begin(), result.end());
    cout << result;
    return 0;
    // fChar에 없으면 넣고 검사시작
    // 5개 이상이면 결과에 넣고 저장
}
