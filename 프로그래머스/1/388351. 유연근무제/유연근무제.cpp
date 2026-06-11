#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getTimeAdd10(int time){
    int hour = time / 100;
    int minute = time % 100;
    minute += 10;
    if (minute >= 60){
        hour++;
        minute %= 60; 
    }
    return hour * 100 + minute;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i =0; i<schedules.size(); i++){
        int cur_day = startday;
        int schedule = getTimeAdd10(schedules[i]);
        vector<int> timelog = timelogs[i];
        bool isReward = true;
        for (int time : timelog){
            if (cur_day == 6){
                cur_day++;
                continue;
            } 
            if (cur_day == 7){
                cur_day = 1;
                continue;
            }
            if (time > schedule){
                // cout << "출근시간: "<<time  <<" 목표시간 : "<< schedule  << "지각!!"<<endl;
                isReward = false;
                break;
            }
            cur_day++;
        }
        if (isReward){
            // cout << i << "번째 직원은 통과" << endl;;
            answer++;
        }
    }
    return answer;
}