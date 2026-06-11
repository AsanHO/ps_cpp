/*
조건을 만족하면 비교 -> 백트래킹
*/
#include <iostream>
#include <string>
using namespace std;
string compares;

long int n;
long int visited[10];  // 0~9
long int min_num = 1000000000;
long int max_num = 0;
string max_result = "000000000000";
string min_result = "999999999999";
void DFS(string str) {
    if (str.size() == n + 1) {
        // todo 비교
        if (str > max_result) {
            max_result = str;
        }
        if (str < min_result) {
            min_result = str;
        }

        return;
    }
    long int left = str[str.size() - 1] - '0';
    char compare = compares[str.size() - 1];
    // cout << left << compare << endl;
    for (long int i = 0; i < 10; i++) {
        long int right = i;
        if (visited[right] == 1) continue;
        if (compare == '<' && left < right) {
            string newstr = str + to_string(right);
            visited[right] = 1;
            DFS(newstr);
            visited[right] = 0;
        }
        if (compare == '>' && left > right) {
            string newstr = str + to_string(right);
            visited[right] = 1;
            DFS(newstr);
            visited[right] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        char c;
        cin >> c;
        compares += c;
    }
    for (long int i = 0; i < 10; i++) {
        visited[i] = 1;
        DFS(to_string(i));
        visited[i] = 0;
    }
    cout << max_result << endl;
    cout << min_result << endl;
    return 0;
}