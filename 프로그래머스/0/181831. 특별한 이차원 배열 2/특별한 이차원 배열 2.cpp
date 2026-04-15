#include <string>
#include <vector>

/*
[19, 498, 258, 587],
[63, 93, 7, 754], 
[258, 7, 1000, 723],
[587, 754, 723, 81]]
*/
using namespace std;

int solution(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            if (arr[i][j] != arr[j][i]){
                return 0;
            }                
        }  
    }
    return 1;
}