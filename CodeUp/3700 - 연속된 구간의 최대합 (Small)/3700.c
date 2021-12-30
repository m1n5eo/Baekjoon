#include <stdio.h>
#include <algorithm>

using namespace std;

int max(int x, int y) {
    return x > y? x:y;
}

int main() {
    int n, arr[100003], dp[100003];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) dp[i] = 1;
    dp[0] = arr[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(arr[i]+dp[i-1], arr[i]);
    }
    sort(dp, dp+n);
    printf("%d", dp[n-1]);
}