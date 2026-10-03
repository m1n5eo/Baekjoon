#include <bits/stdc++.h>
using namespace std;

int card[1003], dp[1003];

int main() {
    int n, mid, maxx;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &card[i]);
    }

    dp[1] = card[1];
    dp[2] = max(dp[1]*2, card[2]);

    for(int i = 3; i <= n; i++) {
        maxx = -1;
        if(i % 2 == 0) {
            mid = (i/2)-1;
            if(maxx < dp[mid+1] + dp[mid+1]) maxx = dp[mid+1] + dp[mid+1];
        }
        else mid = i/2;
        for(int j = 1; j <= mid; j++) {
            if(dp[j] + dp[i-j] > maxx) maxx = dp[j] + dp[i-j];
        }
        if(maxx < card[i]) maxx = card[i];
        dp[i] = maxx;
    }

    // for(int i = 1; i <= n; i++) printf("%d ", dp[i]);
    printf("%d", dp[n]);
}
