#include <bits/stdc++.h>

using namespace std;

int N;  // 포켓몬 개수
int M;  // 문제 개수
map<int, string> pokemonDictionary;
map<string, int> pokemonDictionaryByName;
string result;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++) {
        string pokemonName;
        cin >> pokemonName;
        // pokemonDictionary.insert(make_pair(i,pokemonName));
        pokemonDictionary[i] = pokemonName;
        pokemonDictionaryByName[pokemonName] = i;
    }
    for (int j = 0; j < M; j++) {
        string question;
        cin >> question;
        if (isdigit(question[0])) {
            result = pokemonDictionary[stoi(question)];
        } else {
            result = to_string(pokemonDictionaryByName[question]);
        }
        cout << result << "\n";
    }
    return 0;
}
