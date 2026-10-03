#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

pair<int, vector<int>> solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> profit(n+1, vector<int>(m+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<vector<int>>> trace(n+1, vector<vector<int>>(m+1, vector<int>(0)));
    for(int i = 1; i <= m; i++) {
        int temp; cin >> temp;
        for(int j = 1; j <= n; j++) {
            int p; cin >> p;
            profit[j][i] = p;
        }
    }

    trace[1][0].push_back(0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= j; k++) {
                if(dp[i][j] < dp[i-1][k] + profit[i][j-k]) {
                    dp[i][j] = dp[i-1][k] + profit[i][j-k];
                    trace[i][j].clear();
                    trace[i][j] = trace[i-1][k];
                    trace[i][j].push_back(j-k);
                }
            }
        }
    }

    return {dp[n][m], trace[n][m]};
}

int main() {
    FASTIO
    pair<int, vector<int>> sol = solve();
    cout << sol.first << "\n";
    for(int s : sol.second) cout << s << " ";
}