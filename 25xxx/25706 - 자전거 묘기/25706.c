#include <stdio.h>

#define MAX 222222

int main() {
    int n, jump[MAX], dp[MAX];
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &jump[i]);
    }

    dp[n] = 1;

    for(int i = n-1; i >= 1; i--) {
        if(i + jump[i] + 1 <= n) dp[i] = dp[i+jump[i]+1] + 1;
        else dp[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", dp[i]);
    }
}