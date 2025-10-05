#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

vector<int> solve() {
    int n, m, check = INF;
    cin >> n >> m;
    vector<pair<int, int>> subject(n+1);
    vector<vector<pair<int, pair<int, int>>>> dp(n+1, vector<pair<int, pair<int, int>>>(m+1, {0, {0, 0}}));
    for(int i = 1; i <= n; i++) {
        cin >> subject[i].first >> subject[i].second;
        check = min(check, subject[i].second);
    }

    if(check > m) return {};
    for(int i = 1; i <= n; i++) {
        if(subject[i].second <= m) {
            dp[i][subject[i].second].first = subject[i].first;
            dp[i][subject[i].second].second = {0, i};
        }
        for(int j = 1; j <= m; j++) {
            if(dp[i][j].first < dp[i-1][j].first) dp[i][j] = dp[i-1][j];
            if(j-subject[i].second < 0) continue;
            else if(dp[i-1][j-subject[i].second].first != 0) {
                if(dp[i][j].first < dp[i-1][j-subject[i].second].first + subject[i].first) {
                    dp[i][j].first = dp[i-1][j-subject[i].second].first + subject[i].first;
                    dp[i][j].second = {dp[i-1][j-subject[i].second].second.second, i};
                }
            }
        }
    }

    // cout << "\n" << "dp" << "\n";
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cout << dp[i][j].first << ", " << dp[i][j].second.first << " " << dp[i][j].second.second << " / ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    int k = -1, jdx = -1;
    for(int j = 1; j <= m; j++) {
        if(dp[n][j].first > k) {
            k = dp[n][j].first;
            jdx = j;
        }
    }

    int idx = dp[n][jdx].second.second;
    vector<int> ret;
    while(idx) {
        ret.push_back(idx);
        int i = dp[idx][jdx].second.first;
        int j = jdx-subject[idx].second;
        idx = i, jdx = j;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    if(sol.size() == 0) cout << -1;
    else {
        cout << sol.size() << "\n";
        for(int s : sol) cout << s << " ";
    }
}