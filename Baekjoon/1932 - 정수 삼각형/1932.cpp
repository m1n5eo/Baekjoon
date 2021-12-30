#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main() {
    int n, arr[501][501];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(arr[i][j]+dp[i-1][j], arr[i][j]+dp[i-1][j-1]);
        }
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    sort(dp[n-1], dp[n-1]+n);
    printf("%d", dp[n-1][n-1]);
}
