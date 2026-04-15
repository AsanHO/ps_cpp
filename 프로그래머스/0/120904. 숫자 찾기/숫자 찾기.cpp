#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num, int k) {
    string num_str = to_string(num);
    for (int i = 0; i < num_str.size(); i++){
        if (num_str[i]-'0' == k){
            return i+1;
        }
    }
    return -1;
}