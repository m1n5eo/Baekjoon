#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) cin >> vec[i];

    for(int i = 0; i < n; i++) dp[i][i] = 0;
    for(int i = 0; i < n-1; i++) {
        if(vec[i] == vec[i+1]) dp[i][i+1] = 0;
        else dp[i][i+1] = 1;
    }
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            dp[j][j+(n-i)] = min(dp[j][j+(n-i)], dp[j][j+(n-i)-1] + 1);
            dp[j][j+(n-i)] = min(dp[j][j+(n-i)], dp[j+1][j+(n-i)] + 1);
            dp[j][j+(n-i)] = min(dp[j][j+(n-i)], dp[j+1][j+(n-i)-1] + (vec[j] == vec[j+(n-i)]? 0 : 2));
        }
    }

    // cout << "\n" << "dp" << "\n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(dp[i][j] != INF) cout << dp[i][j] << " ";
    //         else cout << "-" << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    return dp[0][n-1];
}

int main() {
    FASTIO
    cout << solve();
}