#include <stdio.h>

int arr[1003][3], dp[1003][3];

int _min(int a, int b) {
    return a < b? a : b;
}

int main() {
    int n, minn = 2100000000;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i = 1; i < n; i++) {
        dp[i][0] = _min(arr[i][0] + dp[i-1][1], arr[i][0] + dp[i-1][2]);
        dp[i][1] = _min(arr[i][1] + dp[i-1][0], arr[i][1] + dp[i-1][2]);
        dp[i][2] = _min(arr[i][2] + dp[i-1][0], arr[i][2] + dp[i-1][1]);
    }

    for(int i = 0; i < 3; i++) {
        if(dp[n-1][i] < minn) minn = dp[n-1][i];
    }
    printf("%d", minn);
}