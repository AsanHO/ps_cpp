#include <bits/stdc++.h>

using namespace std;

int N;
int result = 0;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        stack<char> wordStack;
        // 좋은단어 조건
        // 1. A와 B가 모두 짝수여야함.
        // 2.겹친다면 앞쌍의 인덱스를 뒷쌍이 포함해야함.
        wordStack.push(word[0]);

        for (int j = 1; j < word.size(); j++) {
            if (wordStack.empty()) {
                wordStack.push(word[j]);
                continue;
            }
            char stack1 = wordStack.top();
            wordStack.push(word[j]);
            if (stack1 == wordStack.top()) {
                wordStack.pop();
                wordStack.pop();
            }
        }

        if (wordStack.empty()) {
            result += 1;
            continue;
        }
    }
    cout << result << "\n";
    return 0;
}
