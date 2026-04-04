/*
레벨화를 시키는 문제로
새로운 아이디어 필요
이분탐색으로
mid를 부모노드
자식노드를 mid기준으로 leftrange, rightrange를 잡고
재귀를 다시 호출해 mid를 계산
기저 사례
1. start와 end가 반전되었을때
2. start와 end가 같을때 이다.

      3
  6       2
1   4   5   7

1 6 4 3 5 2 7
*/
#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

vector<int> result[14];  // 배열안에 벡터가 있는 2차원 리스트 형태
int n;
int a[1030];  // 1028

void InOrder(int start, int end, int level) {
    if (start > end) return;
    if (start == end) {
        result[level].push_back(a[start]);
        return;
    }
    int mid = (start + end) / 2;
    result[level].push_back(a[mid]);
    InOrder(start, mid - 1, level + 1);
    InOrder(mid + 1, end, level + 1);
}
int main() {
    cin >> n;
    int end = (int)pow(2, n) - 1;  // 노드 개수
    for (int i = 0; i < end; i++) {
        cin >> a[i];
    }
    InOrder(0, end, 0);
    for (int i = 0; i < n; i++) {
        for (int nodeValue : result[i]) {
            cout << nodeValue << " ";
        }
        cout << endl;
    }
    return 0;
}