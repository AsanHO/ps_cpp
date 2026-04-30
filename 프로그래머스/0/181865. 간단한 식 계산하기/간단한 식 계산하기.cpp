#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> split(string s){
    vector<string> result;
    string temp;
    for (char c : s){
        if (c == ' '){
            result.push_back(temp);
            temp = "";
        }else{
            temp += c;
        }
    }
    if (temp.size()){
        result.push_back(temp);
    }
    return result;
}
int solution(string binomial) {
    vector<string> strs = split(binomial);
    for (string str: strs){
        cout << str << endl;
    }
    int num1 = stoi(strs[0]);
    string oper = strs[1];
    int num2 = stoi(strs[2]);
    if (oper == "+")
        return num1+num2;
    if (oper == "-")
        return num1-num2;
    if (oper == "*")
        return num1*num2;
    return 0;
}