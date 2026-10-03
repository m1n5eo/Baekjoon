#include <bits/stdc++.h>
using namespace std;

int n, m, arr[501][501], dp[501][501];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
bool check[501][501];

int f(int y, int x) {
    if(y == m && x == n) return 1;
    if(check[y][x]) return dp[y][x];

    check[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int xx = x+a[i];
        int yy = y+b[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
            if(arr[y][x] > arr[yy][xx]) {
                dp[y][x] = dp[y][x] + f(yy, xx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", f(1, 1));
}