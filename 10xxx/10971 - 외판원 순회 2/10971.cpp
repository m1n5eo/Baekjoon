#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 987654321
#define MAX 10

int n;
vector<vector<int>> w(MAX, vector<int>(MAX, 0));
vector<vector<int>> dp(MAX, vector<int>(1<<MAX, INF));

int dfs(int now, int status) {
    if(status == (1<<n)-1) return w[now][0];
    else if(dp[now][status] != INF) return dp[now][status];

    for(int i = 0; i < n; i++) {
        if(w[now][i] == INF) continue;
        else if((status & (1<<i)) == (1<<i)) continue;
        dp[now][status] = min(dp[now][status], w[now][i] + dfs(i, status | (1<<i)));
    }
    return dp[now][status];
}

int solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp; cin >> temp;
            if(temp == 0) w[i][j] = INF;
            else w[i][j] = temp;
        }
    }
    return dfs(0, 1);
}

int main() {
    FASTIO
    cout << solve();
}