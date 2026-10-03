#include <bits/stdc++.h>
using namespace std;

int dp[1001][11];

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i <= 9; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) sum = (sum + dp[i-1][j])%10007;
        dp[i][0] = sum;
        sum = 0;
        for(int j = 1; j <= 9; j++) {
            if(dp[i][j-1]-dp[i-1][j-1] < 0) dp[i][j-1] = dp[i][j-1]+10007;
            dp[i][j] = (dp[i][j-1]-dp[i-1][j-1])%10007;
        }
    }
    for(int i = 0; i <= 9; i++) sum = (sum+dp[n][i])%10007;
    /*for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d", sum%10007);
}
