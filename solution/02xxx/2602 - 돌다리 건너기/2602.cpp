#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    string go, str[2];
    cin >> go >> str[0] >> str[1];
    
    int n = go.size(), m = str[0].size();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
    queue<pair<int, int>> q;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < m; j++) {
            if(str[i][j] == go[0]) {
                dp[i][j][0] = 1;
                q.push({i, j});
            }
        }
    }

    for(int k = 0; k < n-1; k++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i][j][k] != 0) {
                    for(int jj = j+1; jj < m; jj++) {
                        if(str[1-i][jj] == go[k+1]) {
                            dp[1-i][jj][k+1] += dp[i][j][k];
                            q.push({1-i, jj});
                        }
                    }
                }
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < m; j++) {
            ret += dp[i][j][n-1];
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}