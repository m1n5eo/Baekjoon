#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[303], dp[303];

int max(int ii) {
    if(dp[ii-2] + arr[ii] > dp[ii-3] + arr[ii-1] + arr[ii]) return dp[ii-2] + arr[ii];
    else return dp[ii-3] + arr[ii-1] + arr[ii];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    if(dp[0] + arr[2] > arr[1] + arr[2]) dp[2] = dp[0] + arr[2];
    else dp[2] = arr[1] + arr[2];

    for(int i = 3; i < n; i++) {
        dp[i] = max(i);
    }

    printf("%d", dp[n-1]);
}