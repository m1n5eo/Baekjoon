#include <bits/stdc++.h>
using namespace std;

int dp[3][100001];

int main() {
    int t, n, arr[3][100001];
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0]+arr[0][1];
        dp[1][1] = arr[0][0]+arr[1][1];

        for(int i = 2; i < n; i++) {
            dp[0][i] = max(dp[0][i-2]+arr[0][i], dp[1][i-2]+arr[0][i]);
            dp[0][i] = max(dp[0][i], dp[1][i-1]+arr[0][i]);
            dp[1][i] = max(dp[1][i-2]+arr[1][i], dp[0][i-2]+arr[1][i]);
            dp[1][i] = max(dp[1][i], dp[0][i-1]+arr[1][i]);
        }
        /*printf("\n");
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        sort(dp[0], dp[0]+n);
        sort(dp[1], dp[1]+n);
        printf("%d\n", max(dp[0][n-1], dp[1][n-1]));
    }
}
