#include <stdio.h>

int arr[103][103], dp[103][103];

int max(int ii, int jj) {
    return arr[ii][jj] + dp[ii-1][jj] > arr[ii][jj] + dp[ii][jj-1]? arr[ii][jj] + dp[ii-1][jj]:arr[ii][jj] + dp[ii][jj-1];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];

    for(int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + arr[i][0];
    for(int j = 1; j < m; j++) dp[0][j] = dp[0][j-1] + arr[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = max(i, j);
        }
    }

    printf("%d", dp[n-1][m-1]);
}