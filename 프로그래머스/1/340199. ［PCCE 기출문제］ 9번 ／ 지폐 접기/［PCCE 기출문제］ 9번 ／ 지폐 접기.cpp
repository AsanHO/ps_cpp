#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(min(*(bill.begin()),*(bill.end()-1)) > min(*(wallet.begin()),*(wallet.end()-1)) ||
         max(*(bill.begin()),*(bill.end()-1)) > max(*(wallet.begin()),*(wallet.end()-1))){
        if (bill[0] > bill[1]){
            bill[0] /=2;
        }else{
            bill[1] /=2;
        }
        answer++;
    }
    return answer;
}