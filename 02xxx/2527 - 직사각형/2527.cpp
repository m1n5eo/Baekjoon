#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> rec[2][2], rec2[2][2];

bool check_c() {
    if(rec[0][1] == rec[1][0]) return true;
    else if(rec[0][1].first == rec[1][0].first && rec[0][0].second == rec[1][1].second) return true;
    
    return false;
}

bool check_b() {
    if(rec[0][1].first == rec[1][0].first) {
        if(rec[0][0].second <= rec[1][0].second && rec[1][0].second <= rec[0][1].second) return true;
        else if(rec[0][0].second <= rec[1][1].second && rec[1][1].second <= rec[0][1].second) return true;
        else if(rec[0][0].second >= rec[1][0].second && rec[0][1].second <= rec[1][1].second) return true;
    }
    else if(rec[0][1].second == rec[1][0].second || rec[0][0].second == rec[1][1].second) {
        if(rec[0][0].first <= rec[1][0].first && rec[1][0].first <= rec[0][1].first) return true;
        else if(rec[0][0].first <= rec[1][1].first && rec[1][1].first <= rec[0][1].first) return true;
        else if(rec[0][0].first >= rec[1][0].first && rec[0][1].first <= rec[1][0].first) return true;
    }

    return false;
}

bool check_d() {
    if(rec[0][1].second < rec[1][0].second) return true;
    else if(rec[1][1].second < rec[0][0].second) return true;
    else if(rec[0][1].first < rec[1][0].first) return true;

    return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int testcase = 0; testcase < 4; testcase++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> rec[i][j].first >> rec[i][j].second;
                rec2[i][j] = rec[i][j];
            }
        }

        if(rec[0][0].first > rec[1][0].first) {
            swap(rec[0][0], rec[1][0]);
            swap(rec[0][1], rec[1][1]);
        }

        if(check_c() == true) cout << "c\n";
        else if(check_b() == true) cout << "b\n";
        else if(check_d() == true) cout << "d\n";
        else cout << "a\n";
    }

    return 0;
}