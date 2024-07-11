#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    auto max_it = max_element(array.begin(), array.end()); // 최대값의 위치를 찾음
    int max_value = *max_it; // 최대값을 얻음
    answer.push_back(max_value);
    answer.push_back(find(array.begin(), array.end(), max_value) - array.begin());
    return answer;
}