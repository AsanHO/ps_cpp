#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    string order_str = to_string(order);    
    for (char c : order_str){
        if (c=='3' ||c=='6'||c=='9'){
            answer++;
        }
    }
    return answer;
}