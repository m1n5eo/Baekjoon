#include <stdio.h>
#include <algorithm>

using namespace std;

int st[5][100003], dp[5][100003];

int max(int ii, int jj) {
    return dp[ii+1][jj-1] > dp[ii+1][jj-2]? dp[ii+1][jj-1] + st[ii][jj] : dp[ii+1][jj-2] + st[ii][jj];
}

int maxx(int ii, int jj) {
    return dp[ii-1][jj-1] > dp[ii-1][jj-2]? dp[ii-1][jj-1] + st[ii][jj] : dp[ii-1][jj-2] + st[ii][jj];
}

int main() {
    int n, t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &st[i][j]);
            }
        }
        dp[0][0] = st[0][0];
        dp[1][0] = st[1][0];
        dp[0][1] = st[0][1] + dp[1][0];
        dp[1][1] = st[1][1] + dp[0][0];

        for(int j = 2; j < n; j++) {
            for(int i = 0; i < 2; i++) {
                if(i % 2 == 0) {
                    dp[i][j] = max(i, j);
                    if(dp[i][j] < dp[i][j-2] + st[i][j]) dp[i][j] = dp[i][j-2] + st[i][j];
                }
                else {
                    dp[i][j] = maxx(i, j);
                    if(dp[i][j] < dp[i][j-2] + st[i][j]) dp[i][j] = dp[i][j-2] + st[i][j];
                }
            }
        }

        if(dp[0][n-1] > dp[1][n-1]) printf("%d\n", dp[0][n-1]);
        else printf("%d\n", dp[1][n-1]);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
    }
}