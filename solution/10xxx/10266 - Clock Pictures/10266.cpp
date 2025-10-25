#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 360000

string solve() {
    int n;
    cin >> n;
    vector<int> clock(n, 0);
    vector<vector<int>> gap(2, vector<int>(0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) cin >> clock[j];
        sort(clock.begin(), clock.end());
        for(int j = 1; j < n; j++) gap[i].push_back(clock[j] - clock[j-1]);
        gap[i].push_back(clock[0]+INF - clock[n-1]);
    }
    for(int i = 0; i < n; i++) gap[0].push_back(gap[0][i]);

    // cout << "\n" << "gap" << "\n";
    // for(int i = 0; i < 2; i++) {
    //     for(int g : gap[i]) cout << g << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    vector<int> failure(n, 0);
    failure[0] = -1;
    for(int i = 1; i < n; i++) {
        int j = failure[i-1];
        while(gap[1][i] != gap[1][j+1] && j >= 0) j = failure[j];
        if(gap[1][i] == gap[1][j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    int i = 0, j = 0;
    while(i < n*2 && j < n) {
        if(gap[0][i] == gap[1][j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) i += 1;
        else j = failure[j-1]+1;

        if(j == n) return "possible";
    }
    return "impossible";
}

int main() {
    FASTIO
    cout << solve();
}