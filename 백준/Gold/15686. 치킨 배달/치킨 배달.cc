#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
// brute force :: 치킨집을 뽑고, 모든 집과 거리 비교 -> min값을 더한다.
using namespace std;
int N, M, num;

struct KFC {
    pair<int, int> loc;
};

struct House {
    pair<int, int> loc;
    int most_near_kfc_idx;
    int most_near_kfc_distance;
};

void PrintV(vector<int> v, int result) {
    for (auto n : v) cout << n << " ";
    cout << "들과 집들의 최소거리 합 : " << result << endl;
}
class Chicken {
   public:
    vector<KFC> kfcs;
    vector<pair<int, int>> house_locs;
    int sum_dist = 99999999;
    void combi(int start, vector<int> b, const int& kfc_count) {
        if (b.size() == M) {
            int dist = check_distance(b);
            // PrintV(b, dist);
            if (sum_dist > dist) sum_dist = dist;
            return;
        }
        for (int i = start + 1; i < kfc_count; i++) {
            b.push_back(i);
            combi(i, b, kfc_count);
            b.pop_back();
        }
        return;
    }
    int check_distance(vector<int> kfc_idxs) {
        int result = 0;
        for (auto loc : house_locs) {
            int most_near_dist = 99999;
            for (int i : kfc_idxs) {
                int dist = abs(kfcs[i].loc.first - loc.first) + abs(kfcs[i].loc.second - loc.second);
                // cout << dist << endl;
                if (most_near_dist > dist) {
                    most_near_dist = dist;
                }
            }
            // cout << loc.first << ":" << loc.second << "의 최소 치킨 거리" << most_near_dist << endl;
            result += most_near_dist;
        }
        return result;
    }
    void combi_kfc() {
        // cout << "제거 개수 : " << init_size - M << endl; // 제거가 아니라 조합을 생각해야함
        vector<int> survivedKfc;

        combi(-1, survivedKfc, kfcs.size());
    }
    // void check_dist(House house) {
    //     for (KFC& kfc : kfcs) {
    //         for (pair<int, int> home : house.locs) {
    //             int dist = abs(kfc.loc.first - home.first) + abs(kfc.loc.second - home.second);
    //             // cout << "kfc " << kfc.loc.first << " : " << kfc.loc.second << " -> ";
    //             // cout << home.first << " : " << home.second << " = " << dist << endl;
    //             kfc.dists.push_back(dist);
    //         }
    //         int sum_dist = 0;
    //         for (int dist : kfc.dists) {
    //             // cout << dist << endl;
    //             kfc.sum_dist += dist;
    //         }
    //         // cout << kfc.loc.first << ":" << kfc.loc.second << "=" << kfc.sum_dist << endl;
    //     }
    // }

    // int getSumMinDist(House house) {
    //     int result = 0;
    //     for (auto loc : house.locs) {
    //         int minDist = 200;
    //         for (KFC kfc : kfcs) {
    //             int dist = abs(kfc.loc.first - loc.first) + abs(kfc.loc.second - loc.second);
    //             // cout << loc.first << ":" << loc.second << "->" << kfc.loc.first << ":" << kfc.loc.second << " = " << dist << endl;

    //             if (dist < minDist) {
    //                 minDist = dist;
    //             }
    //         }
    //         // cout << minDist << endl;

    //         result += minDist;
    //     }
    //     return result;
    // }
};

int main() {
    Chicken kfc;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            if (num == 1) kfc.house_locs.push_back(make_pair(i, j));
            if (num == 2) kfc.kfcs.push_back(KFC{make_pair(i, j)});
        }
    }
    // kfc.check_dist(house);
    kfc.combi_kfc();
    // cout << kfc.kfcs.size() << endl;
    // cout << kfc.getSumMinDist(house) << endl;
    cout << kfc.sum_dist << endl;
    return 0;
}