#include <bits/stdc++.h>

using namespace std;


bool isdecimal(int n){
    if (n == 2){
        return true;
    }
    if ((n <= 1) || (n % 2==0)){
        return false;
    }
    
    for (int i =3; i * i <=n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

void print(vector<int>v){
    for (auto i :v){
        cout << i << "\n";
    }
}
int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> nums;
    int count = 0;
    for (size_t i = 2; i <=n; i++){
        nums.push_back(i);
    }
    
    while (nums.size() > 0){
        int p = *nums.begin();
        int b = 1;
        while (p * b <= n){  // 이 부분에서 >= 를 <=로 수정해야 올바른 검사가 이루어집니다.
            auto it = find(nums.begin(), nums.end(), p * b);
            if (it != nums.end()) {
                count += 1;
                if (count == k){
                    cout << *it << '\n';
                    break;
                }
                
                nums.erase(it);
                
            }
            b += 1;
        }
        // print(nums);
        if (nums.size() == 0){
            break;
        }
    }
    return 0;
}
