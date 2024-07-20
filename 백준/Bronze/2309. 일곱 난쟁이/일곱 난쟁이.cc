#include <bits/stdc++.h>

using namespace std;

vector<int> mans;
vector<int> v;
vector<vector<int>> indexes;

void print(vector<int> v){
    for (auto i : v){
        cout << i;
    }
    cout << '\n';
}

void combi(int start,vector<int> v){
    if (v.size() == 7){
        indexes.push_back(v);
        return;
    }
    for (int i = start+1; i < 9; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(int argc, char const *argv[]){
    
    for (int i = 0; i<9;i++){
        int man;
        cin >> man;
        mans.push_back(man);
    }
    sort(mans.begin(),mans.end());
    // print(mans);
    combi(-1,v);

    for (vector<int> index : indexes){
        int sum = 0;
        for (int i : index){
            sum += mans[i];
        }
        if (sum == 100){
            for (int i : index){
                cout << mans[i];
                cout << '\n';

            }  
            
            break;
        }
    }
    return 0;
}
