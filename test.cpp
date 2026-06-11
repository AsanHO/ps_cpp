#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct Student {
    int position;       // 집 좌표
    int schoolNumber;   // 학교 번호
    int studentNumber;  // 원래 학생 번호
};

void countFriends(vector<pair<int, int>>& students, ll maxDistance, vector<ll>& friendCount, int value) {
    int studentSize = students.size();

    vector<ll> prefixDiff(studentSize + 1, 0);

    int left = 0;

    for (int right = 0; right < studentSize; right++) {
        while (students[right].first - students[left].first > maxDistance) left++;

        // 현재 학생이 추가하는 친구 수
        friendCount[students[right].second] += value * (right - left);

        // left ~ right-1 학생들도 현재 학생과 친구
        prefixDiff[left] += value;
        prefixDiff[right] -= value;
    }

    ll prefixSum = 0;

    for (int i = 0; i < studentSize; i++) {
        prefixSum += prefixDiff[i];

        friendCount[students[i].second] += prefixSum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int studentCount;
    ll k1, k2;

    cin >> studentCount >> k1 >> k2;

    vector<Student> students(studentCount);

    for (int i = 0; i < studentCount; i++) {
        cin >> students[i].position >> students[i].schoolNumber;

        students[i].studentNumber = i;
    }

    vector<ll> friendCount(studentCount, 0);

    // 전체 학생 저장
    vector<pair<int, int>> allStudents;

    for (auto& student : students) {
        allStudents.push_back({student.position, student.studentNumber});
    }

    sort(allStudents.begin(), allStudents.end());

    // 서로 다른 학교 기준 거리(K2)
    countFriends(allStudents, k2, friendCount, +1);

    // 학교별 학생 저장
    vector<vector<pair<int, int>>> studentsBySchool(studentCount + 1);

    for (auto& student : students) {
        studentsBySchool[student.schoolNumber].push_back({student.position, student.studentNumber});
    }

    for (int school = 1; school <= studentCount; school++) {
        auto& sameSchoolStudents = studentsBySchool[school];

        if (sameSchoolStudents.empty()) continue;

        sort(sameSchoolStudents.begin(), sameSchoolStudents.end());

        // 같은 학교 거리(K1) 추가
        countFriends(sameSchoolStudents, k1, friendCount, +1);

        // 이미 더해진 K2 제거
        countFriends(sameSchoolStudents, k2, friendCount, -1);
    }

    for (ll count : friendCount) cout << count << ' ';

    return 0;
}