#include <stdio.h>

#define lli long long int

lli n, dp[33];

int main() {
    dp[2] = 1;

    scanf("%lld", &n);
    
    for(lli i = 4; i <= n; i+=2) {
        dp[i] = dp[i-2]*(i-1);
    }

    printf("%lld", dp[n]);

    return 0;
}