#include <bits/stdc++.h>
using namespace std;

int arr[100003], dp[100003];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }
    dp[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(dp[i] < dp[i-1] + arr[i]) dp[i] = dp[i-1] + arr[i];
    }
    sort(dp, dp+n);
    printf("%d", dp[n-1]);
}
