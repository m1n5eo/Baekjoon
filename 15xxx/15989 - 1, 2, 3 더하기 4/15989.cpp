#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int main() {
    FASTIO

    int t, n;
    vector<vector<int>> dp(MAX, vector<int>(4, 0));

    dp[1] = {0, 1, 0, 0};
    dp[2] = {0, 1, 1, 0};
    dp[3] = {0, 1, 1, 1};

    for(int i = 4; i < MAX; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
}