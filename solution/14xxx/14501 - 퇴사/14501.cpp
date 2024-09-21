#include <bits/stdc++.h>
using namespace std;

int day[22], money[22], dp[22];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &day[i], &money[i]);
        if(day[i]+i > n+1) {
            day[i] = 0;
            money[i] = 0;
        }
    }

    dp[1] = money[1];

    for(int i = 2; i <= n; i++) {
        dp[i] = money[i];
        for(int j = 1; j < i; j++) {
            if(day[j]+j <= i) {
                dp[i] = max(dp[i], money[i]+dp[j]);
            }
        }
    }

    /*for(int i = 1; i <= n; i++) printf("%d ", dp[i]);
    printf("\n");*/

    sort(dp+1, dp+n+1);
    printf("%d", dp[n]);
}
