#include <stdio.h>

int main() {
    int n, cnt = 1, sum = 0;
    scanf("%d", &n);
    int br[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            br[i][j] = cnt;
            cnt = cnt + 1;
            if(i == 1) sum = sum + br[i][j];
            else if(j == 1) sum = sum + br[i][j];
            else if(i == n) sum = sum + br[i][j];
            else if(j == n) sum = sum + br[i][j];
        }
    }
    printf("%d", sum);
}