#include <bits/stdc++.h>
using namespace std;

int dp[10003];

int main() {
    int n, arr[10003];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    //for(int i = 0; i < n; i++) printf("%d ", dp[i]);

    sort(dp, dp+n);
    printf("%d", dp[n-1]);
}
