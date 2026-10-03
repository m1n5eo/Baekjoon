#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 16

int n;
vector<vector<int>> w(MAX, vector<int>(MAX, 0));
vector<vector<int>> dp(MAX, vector<int>(1<<MAX, -1));

int dfs(int now, int status) {
    if(status == (1<<n)-1) {
        if(w[now][0] == 0) return INF;
        else return w[now][0];
    }
    else if(dp[now][status] != -1) return dp[now][status];

    dp[now][status] = INF;
    for(int i = 0; i < n; i++) {
        if(w[now][i] == 0) continue;
        else if((status & (1<<i)) == (1<<i)) continue;
        dp[now][status] = min(dp[now][status], w[now][i] + dfs(i, status | (1<<i)));
    }

    return dp[now][status];
}

int solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    return dfs(0, 1);
}

int main() {
    FASTIO
    cout << solve();
}