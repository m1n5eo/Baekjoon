#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[103], dp[103];

int max(int _i) {
    if(dp[_i-2] + arr[_i] > arr[_i-1] + arr[_i] + dp[_i-3]) return dp[_i-2] + arr[_i];
    else return arr[_i-1] + arr[_i] + dp[_i-3];
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
        if(dp[i] < dp[i-1]) dp[i] = dp[i-1];
    }

    printf("%d", dp[n-1]);
}