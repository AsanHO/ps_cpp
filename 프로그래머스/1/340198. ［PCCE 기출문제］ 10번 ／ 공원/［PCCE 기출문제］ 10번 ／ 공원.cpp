#include <string>
#include <vector>
#include <iostream>
/*
["A", "A", "-1", "B", "B", "B", "B", "-1"], 
["A", "A", "-1", "B", "B", "B", "B", "-1"],
["-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"],
["D", "D", "-1", "-1", "-1", "-1", "E", "-1"], 
["D", "D", "-1", "-1", "-1", "-1", "-1", "F"], 
["D", "D", "-1", "-1", "-1", "-1", "E", "-1"]]
*/
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    cout << "세로길이 "<<park.size()  << endl;
    cout << "가로길이 "<<park[0].size()  << endl;
    for (int mat : mats){
        for (int i = 0; i<park.size(); i++){
            for (int j = 0; j<park[0].size(); j++){
                bool flag = true;
                
                for (int r = 0; r < mat; r++){
                    for (int c = 0; c < mat; c++){
                            if (i+r >= park.size() || j+c >= park[0].size()){
                                flag = false;
                                continue;
                            }
                            
                            if (park[i+r][j+c] != "-1"){
                                flag = false;
                                continue;
                            }
                    }
                }
                if (flag){
                    if (answer < mat){
                        answer = mat;
                    }
                }
            }
        }
    }
    return answer;
}