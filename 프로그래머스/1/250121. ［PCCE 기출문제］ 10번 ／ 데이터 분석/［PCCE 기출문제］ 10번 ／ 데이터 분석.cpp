#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> datas, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int targetIdx =
        ext == "code" ? 0 :
        ext == "date" ? 1 :
        ext == "maximum" ? 2 : 3;

    int sortByIdx =
        sort_by == "code" ? 0 :
        sort_by == "date" ? 1 :
        sort_by == "maximum" ? 2 : 3;
    for(auto data : datas){
        if (data[targetIdx] < val_ext){
            answer.push_back(data);
        }
    }
    sort(answer.begin(),answer.end(),[sortByIdx](vector<int> a, vector<int> b){return a[sortByIdx] < b[sortByIdx];});
    return answer;
}