#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
double avg_sum = 0;
double sum = 0;

int main() {
    for (int i = 0; i < 20; i++) {
        string class_name;
        double score;
        string grade;
        cin >> class_name >> score >> grade;
        if (grade == "P") {
            continue;
        }
        if (grade == "A+") {
            avg_sum += score * 4.5;
        }
        if (grade == "A0") {
            avg_sum += score * 4.0;
        }
        if (grade == "B+") {
            avg_sum += score * 3.5;
        }
        if (grade == "B0") {
            avg_sum += score * 3.0;
        }
        if (grade == "C+") {
            avg_sum += score * 2.5;
        }
        if (grade == "C0") {
            avg_sum += score * 2.0;
        }
        if (grade == "D+") {
            avg_sum += score * 1.5;
        }
        if (grade == "D0") {
            avg_sum += score * 1.0;
        }
        if (grade == "F") {
            avg_sum += score * 0.0;
        }
        sum += score;
    }
    cout << fixed << setprecision(6) << avg_sum / sum << endl;
    return 0;
}