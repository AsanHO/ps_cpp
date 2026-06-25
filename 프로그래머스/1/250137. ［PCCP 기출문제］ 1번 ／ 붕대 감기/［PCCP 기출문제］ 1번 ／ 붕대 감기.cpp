/*
붕대 감기
- t초 동안 1초마다 x체력 회복
- t초 연속으로 붕대 감으면 y체력 추가 회복
- 최대체력보다 커지는건 불가
- 도중에 공격당하면 기술 취소, 연속 성공 0으로 초기화
- 체력이 0 이하가 되면 캐릭터가 죽음
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int prevTime = 0;
    int needTime = bandage[0];
    int secH = bandage[1];
    int addH = bandage[2];
    int maxH = health;
    for (vector<int> attack : attacks){
        int curTime = attack[0];
        int timeStack = curTime - prevTime -1; // 공격당시에는 회복 할수 없으므로
        prevTime = curTime;
        int totalAddH = 0;
        if (timeStack < needTime){
            totalAddH = timeStack * secH;
        }else{
            totalAddH = timeStack * secH;
            int addHealth = timeStack / needTime * addH;
            totalAddH += addHealth;
        }
        health += totalAddH;
        if (health > maxH) health = maxH;
        cout << "공격전 : "<<health << endl;
        health -= attack[1];
        cout << "공격후 : "<<health << endl;
        if (health <= 0) return -1;
    }
    return health;
}