/*
비트마스킹으로 모든경우의 수를 확인하고,
연결된 컴포넌트가 2개인 경우에만 인구수 체크
*/

/*
동전의 최소개수를 구한다.
최소개수는 2개보다 작을수 없다. 최소 2개
n이 3개일때 마스킹은 6개까지 수행 2*3
*/
#include <algorithm>
#include <iostream>
using namespace std;

int pops[20];
vector<int> components[20];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}