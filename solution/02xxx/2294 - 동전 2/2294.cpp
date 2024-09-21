#include <bits/stdc++.h>
using namespace std;

int coin[101], dp[101][100001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);
    sort(coin+1, coin+n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = 12345678;
        }
    }
    for(int i = coin[1]; i <= k; i+=coin[1]) dp[1][i] = i/coin[1];

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < coin[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]]+1);
        }
    }
    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }*/
    if(dp[n][k] == 12345678) dp[n][k] = -1;
    printf("%d", dp[n][k]);
}
