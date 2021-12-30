#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k = 1, x, y, arr[101][101];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        x = n, y = i;
        while(x >= 1 && x <= n && y >= 1 && y <= m) {
            arr[x][y] = k;
            k = k+1;
            x = x-1;
            y = y-1;
        }
    }
    for(int i = n-1; i >= 1; i--) {
        x = i, y = m;
        while(x >= 1 && x <= n && y >= 1 && y <= m) {
            arr[x][y] = k;
            k = k+1;
            x = x-1;
            y = y-1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}