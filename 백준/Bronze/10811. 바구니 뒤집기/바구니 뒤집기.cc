/*
범위를 뒤집는 문제

12345 14
43215
swap함수를 만들고
14
23으로 a 와 b의 차가 1이거나 0이면 break를 건다.
*/
#include <iostream>

using namespace std;
int N;
int M;
int bag[104];
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
/*
12345
21345
21435
34125
*/
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        bag[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // cout << a << b << "start" << endl;
        do {
            swap(bag[a], bag[b]);
            a++;
            b--;
        } while (b - a >= 1);
        }
    for (int i = 1; i <= N; i++) {
        cout << bag[i] << " ";
    }
    cout << endl;
    return 0;
}