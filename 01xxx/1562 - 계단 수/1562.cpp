#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000000

int n;
vector<vector<vector<lli>>> dp(101, vector<vector<lli>>(10, vector<lli>((1<<10), 0)));

lli solve() {
    cin >> n;
    for(int i = 1; i < 10; i++) dp[1][i][1<<i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < (1<<10); k++) {
                if(j == 0) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j+1][k]) % MOD;
                else if(j == 9) dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k]) % MOD;
                else dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
            }
        }
    }
    
    lli ret = 0;
    for(int j = 0; j < 10; j++) ret = (ret + dp[n][j][(1<<10)-1]) % MOD;
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}