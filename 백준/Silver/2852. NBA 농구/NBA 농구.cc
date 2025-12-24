#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);                        // delimiter가 나온 첫번째 인덱스
    while (end != string::npos) {                            // 가 npos가 아닐때 반복
        result.push_back(input.substr(start, end - start));  // 나왔다면 자
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));  // 마지막 까지 자르기
    return result;
}
int team1score = 0;
int team1mm = 0;
int team1ss = 0;
int team2score = 0;
int team2mm = 0;
int team2ss = 0;
vector<vector<string>> scores;

void addTime(const int& team, const int& mm, const int& ss) {
    // cout << team << "에 득점시간 추가 " << mm << " : " << ss << endl;
    if (team == 1) {
        team1mm += mm;
        team1ss += ss;
    } else {
        team2mm += mm;
        team2ss += ss;
    }
    // 값 보정
    if (team1ss > 59) {
        team1mm += team1ss / 60;
        team1ss = team1ss % 60;
    }
    if (team2ss > 59) {
        team2mm += team2ss / 60;
        team2ss = team2ss % 60;
    }
    if (team1ss < 0) {
        team1mm--;
        team1ss += 60;
    }
    if (team2ss < 0) {
        team2mm--;
        team2ss += 60;
    }
}
string padTime(const int& time) {
    string result = "";
    if (time < 10) {
        result += "0";
        result += to_string(time);
        return result;
    }
    return to_string(time);
}
int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        string team;
        cin >> team;
        string inputString;
        cin >> inputString;
        vector<string> score;
        score.push_back(team);
        score.push_back(inputString);
        scores.push_back(score);
    }
    if (scores.size() == 1) {  // 스코어가 단 하나 일 경우
        vector<string> score = scores[0];
        int team = stoi(score[0]);
        vector<string> scoreTime = split(score[1], ":");
        int mm = stoi(scoreTime[0]);
        int ss = stoi(scoreTime[1]);
        addTime(team, 48 - mm, 0 - ss);
    }
    for (long unsigned int i = 1; i < scores.size(); i++) {
        if (i == 1) {
            (stoi(scores[0][0]) == 1) ? team1score++ : team2score++;
            // cout << team1score << " VS " << team2score << endl;
        }
        vector<string> score = scores[i];
        vector<string> prevScore = scores[i - 1];
        vector<string> prevScoreTime = split(prevScore[1], ":");
        // int prevTeam = stoi(prevScore[0]);
        int prevMm = stoi(prevScoreTime[0]);
        int prevSs = stoi(prevScoreTime[1]);
        vector<string> scoreTime = split(score[1], ":");
        int team = stoi(score[0]);
        int mm = stoi(scoreTime[0]);
        int ss = stoi(scoreTime[1]);
        int resultMm = 0;
        int resultSs = 0;
        resultMm = mm - prevMm;
        resultSs = ss - prevSs;
        if (resultSs < 0) {
            resultMm--;
            resultSs += 60;
        }
        if (team1score > team2score) {
            addTime(1, resultMm, resultSs);
        } else if (team1score < team2score) {
            addTime(2, resultMm, resultSs);
        }
        team == 1 ? team1score++ : team2score++;
        // cout << team1score << " VS " << team2score << endl;
        if (i == scores.size() - 1) {
            if (team1score > team2score) {
                addTime(1, 48 - mm, 0 - ss);
            } else if (team1score < team2score) {
                addTime(2, 48 - mm, 0 - ss);
            }
            break;
        }
    }

    cout << padTime(team1mm) << ":" << padTime(team1ss) << endl;
    cout << padTime(team2mm) << ":" << padTime(team2ss) << endl;
    return 0;
}