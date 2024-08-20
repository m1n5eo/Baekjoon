#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 1000000009
#define MAX 111111

int main() {
    FASTIO

    int dp[MAX][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}, };

    for(int i = 4; i < MAX; i++) {
        dp[i][1] = (dp[i-1][2]+dp[i-1][3])%MOD;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3])%MOD;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2])%MOD;
    }
    
    int t;
    
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n;

        cin >> n;
        cout << ((dp[n][1]+dp[n][2])%MOD+dp[n][3])%MOD << "\n";
    }
}