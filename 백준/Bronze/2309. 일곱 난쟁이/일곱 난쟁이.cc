#include <bits/stdc++.h>

using namespace std;

vector<int> dwarfs;
vector<int> mem;
vector<vector<int> > indexes;
int k = 7;
void print(vector<int> b) {
    for (int i : b) cout << i << "\n";
}
void combi(int start, vector<int> &b) {
    if (b.size() == k) {
        indexes.push_back(b);
        return;
    }
    for (int i = start + 1; i < 9; i++) {
        b.push_back(dwarfs[i]);
        combi(i, b);
        b.pop_back();
    }
}
int sum(vector<int> list) {
    int sum = 0;
    for (int i : list) {
        sum += i;
    }
    return sum;
}
int main(int argc, char const *argv[]) {
    for (int i = 0; i < 9; i += 1) {
        int input;
        cin >> input;
        dwarfs.push_back(input);
    }
    combi(-1, mem);
    for (vector<int> nanjeng : indexes) {
        if (sum(nanjeng) == 100) {
            sort(nanjeng.begin(), nanjeng.end());
            print(nanjeng);
            break;
        }
    }

    return 0;
}
