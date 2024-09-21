#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k;

    cin >> n >> k;
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    vector<int> weight(n+1, 0), value(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= k; w++) {
            if(weight[i] <= w) dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][k];
}