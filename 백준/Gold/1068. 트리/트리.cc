#include <iostream>
#include <vector>
using namespace std;
// 트리를 구현할 필요는 없음
int n;
int temp;
int root;
int removeTarget;
vector<int> tree[54];  // vector<int> 54개

int DFS(int num) {
    if (tree[num].empty() && num == root) return 1;
    int result = 0;
    int child = 0;
    for (int childNode : tree[num]) {
        // cout << num << " 의 자식 " << childNode << endl;
        result += DFS(childNode);
        child++;
    }
    if (child == 0) {
        // cout << num << "은 자식 노드 없음" << endl;
        return 1;
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1)
            root = i;
        else
            tree[temp].push_back(i);
    }

    cin >> removeTarget;
    if (root == removeTarget) {
        cout << 0 << endl;
    } else {
        tree[removeTarget].clear();
        for (int i = 0; i < 54; i++) {
            // cout << i << " : ";
            if (tree[i].size() > 0)
                for (int j = 0; j < tree[i].size(); j++) {
                    if (tree[i][j] == removeTarget) {
                        tree[i].erase(tree[i].begin() + j);
                    }
                    // cout << tree[i][j] << " -> ";
                }
            // cout << endl;
        }
        cout << DFS(root) << endl;
    }

    return 0;
}
