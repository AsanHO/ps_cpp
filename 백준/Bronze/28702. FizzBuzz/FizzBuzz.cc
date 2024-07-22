#include <bits/stdc++.h>

using namespace std;


string q,w,e;
int answer;
int main(int argc, char const *argv[]){
    cin >> q;
    cin >> w;
    cin >> e;
    // cout << atoi(q.c_str()) <<atoi(w.c_str())<< atoi(e.c_str());
    if (atoi(q.c_str()) != 0){
        answer = atoi(q.c_str()) +3;
        
    }
    else if (atoi(w.c_str()) != 0){
        answer = atoi(w.c_str()) +2;
        
    }
    if (atoi(e.c_str()) != 0){
        answer = atoi(e.c_str()) +1;
        
    }

    if (answer%3==0 && answer%5==0 ){
        cout << "FizzBuzz";    
    }else if (answer%3==0){
        cout << "Fizz";    
    }
    else if (answer%5==0){
        cout << "Buzz";    
    }else{
        cout << answer ;
    }
    
   return 0;
}
