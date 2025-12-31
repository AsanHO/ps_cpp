#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
// 자료 구조를 총 3개 써야함
using namespace std;
int N, arr[1000004], result[1000004];
stack<int> st;
int main() {
    cin >> N;
    memset(result, -1, sizeof(result));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        while (st.size() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}