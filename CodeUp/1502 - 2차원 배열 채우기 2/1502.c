#include <stdio.h>

int main() {
    int n, cnt = 1;
    scanf("%d", &n);
    int br[n+1][n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            br[j][i] = cnt;
            cnt++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", br[i][j]);
        }
        printf("\n");
    }
}