#include <string>
#include <vector>
#include <iostream>
// 해싱사용할 것!!
#include <map>
using namespace std;

map<string, int> playerMap;
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for (int i = 0; i < players.size(); i++) {
        playerMap[players[i]] = i;
    }
    for (string call : callings) {
        int cur_rank = playerMap[call];
        
        string temp = players[cur_rank - 1];
        playerMap[temp] ++;
        playerMap[call] --;
        players[cur_rank - 1] = players[cur_rank];
        players[cur_rank] = temp;
    }
    return players;
}