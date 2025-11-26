/*
1.모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
2.모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
3.같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/
#include <iostream>
#include <string>

using namespace std;

void printNot(string word) { cout << "<" << word << "> is not acceptable." << endl; }
void print(string word) { cout << "<" << word << "> is acceptable." << endl; }

bool isContainVowel(string word) {
    if (!(word.find("a") == string::npos)) return true;
    if (!(word.find("e") == string::npos)) return true;
    if (!(word.find("i") == string::npos)) return true;
    if (!(word.find("o") == string::npos)) return true;
    if (!(word.find("u") == string::npos)) return true;
    return false;
}

bool isConsecutive3(string word) {
    int vowelCount = 0;
    int consonantCount = 0;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            consonantCount = 0;
            vowelCount++;
        } else {
            vowelCount = 0;
            consonantCount++;
        }
        if (consonantCount == 3 || vowelCount == 3) {
            return true;
        }
    }
    return false;
}
bool isDouble(string word) {
    for (int i = 0; i < word.size() - 1; i++) {
        if (word[i] == word[i + 1] && !(word[i] == 'e' || word[i] == 'o')) {
            return true;
        }
    }
    return false;
}
int main() {
    while (true) {
        string word;
        bool isAcceptable = false;
        cin >> word;

        if (word == "end") break;
        if (!isContainVowel(word)) {
            printNot(word);
            continue;
        }
        if (isConsecutive3(word)) {
            printNot(word);
            continue;
        }
        if (isDouble(word)) {
            printNot(word);
            continue;
        }
        print(word);
    }
    return 0;
}