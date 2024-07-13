#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    int N;
    vector<int> note1;
    int M;
    vector<int> note2;
    cin >> T;
    
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        for (size_t i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            note1.push_back(n);
        }
        cin >> M;
        for (size_t i = 0; i < M; i++)
        {
            int n;
            cin >> n;
            note2.push_back(n);
        }

    
    // // cout << "\n";
    // for (int n : note2){
    //     // cout << n << " ";
    // }
    sort(note1.begin(),note1.end());
    for (int n2 : note2){
        int answer = 0;
        int l = 0,r = note1.size() - 1; 
	    int mid; 
        while(l <= r){
            mid = (l + r) / 2; 
            if(note1[mid] > n2)r = mid - 1; 
            else if(note1[mid] == n2) {
                answer = 1;
                break;
            }
            else l = mid + 1; 
        }
        cout << answer << "\n";
    }
    note1.clear();
    note2.clear();
    }

    
}
