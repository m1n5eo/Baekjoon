#include <bits/stdc++.h>
using namespace std;

int w[101], v[101], dp[101][100001];

int main() {
    int n, k, maxx = -1234567890;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(j >= w[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i][k] > maxx) maxx = dp[i][k];
    }
    printf("%d", maxx);
}