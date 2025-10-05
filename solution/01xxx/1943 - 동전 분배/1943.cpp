#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve(int n) {
    int a, b, total = 0;
    vector<pair<int, int>> coin(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> coin[i].first >> coin[i].second;
        total += coin[i].first * coin[i].second;
    }

    if(total%2 == 1) return 0;
    vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = coin[i].first; j <= total; j++) {
            if(dp[i-1][j-coin[i].first] == 1) {
                dp[i][j-coin[i].first] = 1;
                for(int k = 0; k < coin[i].second; k++) {
                    if(j + coin[i].first*k <= total) {
                        dp[i][j + coin[i].first*k] = 1;
                    }
                }
            }
        }
    }

    // cout << "\n" << "dp" << "\n";
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= total; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    if(dp[n][total/2] == 1) return 1;
    else return 0;
}

int main() {
    FASTIO
    int n;
    while(cin >> n) cout << solve(n) << "\n";
}