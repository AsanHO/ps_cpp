
#include <iostream>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    for (int h = 0; h < H; h++) {
        int result = -1;
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;

            if (c == 'c') {
                result = 0;
            } else if (result > -1) {
                result++;
            }
            cout << result << " ";
        }
        cout << endl;
    }
    return 0;
}