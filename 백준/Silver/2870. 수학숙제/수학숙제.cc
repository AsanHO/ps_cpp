#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> numbers;
int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string s;
        cin >> s;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // cout << c << endl;
            if ('0' <= c && c <= '9') {
                result += c;
            } else {
                if (result != "") {
                    while (result[0] == '0') {
                        if (result.size() == 1) {
                            break;
                        }
                        result.erase(0, 1);
                    }
                    numbers.push_back(result);
                }
                result = "";
            }
            if (i == s.size() - 1) {
                if (result != "") {
                    // 앞에 0이 있다면 제거 해야함
                    while (result[0] == '0') {
                        if (result.size() == 1) {
                            break;
                        }
                        result.erase(0, 1);
                    }

                    numbers.push_back(result);
                }
            }
        }
    }
    // sort(numbers.begin(), numbers.end());
    sort(numbers.begin(), numbers.end(), [](string a, string b) {
        if (a.size() > b.size()) {
            return false;
        }
        if (a.size() == b.size()) {
            return a < b;
        }
        return true;
    });
    for (string n : numbers) {
        cout << n << endl;
    }
    return 0;
}