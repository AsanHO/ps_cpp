#include <bits/stdc++.h>

using namespace std;

vector<int> s;
int l;
int r;

int main(int argc, char const *argv[]){
    cin >> l;
    cin >> r;
    if (l < r){
        cout << "<";
        return 0;    
    }
    if (l > r){
        cout << ">";
        return 0;    
    }
    if (l == r){
        cout << "==";
        return 0;    
    }

    
   return 0;
}
