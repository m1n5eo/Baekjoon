#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k;

    cin >> k >> n;
    
    vector<int> level(n+1, 0), time(n+1, 0);
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i = 1; i <= n; i++) {
        cin >> level[i] >> time[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int t = 1; t <= k; t++) {
            if(time[i] <= t) dp[i][t] = max(dp[i-1][t], dp[i-1][t-time[i]] + level[i]);
            else dp[i][t] = dp[i-1][t];
        }
    }

    cout << dp[n][k];
}