#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1003][33], dp[1003][33];

int min(int ii, int jj) {
    int max = 2100000000;
    for(int check = 0; check < 3; check++) {
        if(jj != check && max > dp[ii-1][check] + arr[ii][jj]) {
            max = dp[ii-1][check] + arr[ii][jj];
        }
    }
    return max;
}

int main() {
    int n, max = 2100000000;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) dp[0][i] = arr[0][i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = min(i, j);
        }
    }

    for(int i = 0; i < 3; i++) {
        if(max > dp[n-1][i]) max = dp[n-1][i];
    }
    printf("%d", max);
}