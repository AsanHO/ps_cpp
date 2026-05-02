#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string temp;
    if (myString[0] == 'x'){
        myString.erase(myString.begin());
    }
    for (char c : myString){
        if (c == 'x'){
            if (temp.size()){
                answer.push_back(temp);    
            }
            
            temp = "";
        }else{
            temp += c;
        }
        
    }
    if (temp.size()){
        answer.push_back(temp);
    }
    sort(answer.begin(),answer.end());
    return answer;
}