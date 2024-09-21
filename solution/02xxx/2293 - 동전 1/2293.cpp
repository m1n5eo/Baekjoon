#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, dp[10001]={}, coin[103];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    dp[0]=1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j>=coin[i]) {
                dp[j] = dp[j] + dp[j-coin[i]];
            }
        }
        /*for(int j = 1; j <= k; j++) printf("%d ", dp[j]);
        printf("\n");*/
    }
    printf("%d", dp[k]);
}
