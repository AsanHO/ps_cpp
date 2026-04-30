#include <string>
#include <vector>
/*
ihrh
bakr
fpnd
oplj
hygc
*/
using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    for (int i =0; i < my_string.size()/m; i++){
        answer += my_string[i*m+c-1];
    }
    return answer;
}