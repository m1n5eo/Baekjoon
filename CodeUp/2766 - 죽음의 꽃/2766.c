#include <stdio.h>

int main() {
    int n, k, x, y, sum = 0, flower[103][103];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            scanf("%d", &flower[i][j]);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        for(int f = -1; f <= 1; f++) {
            for(int t = -1; t <= 1; t++) {
                flower[x+f][y+t] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum = sum + flower[i][j];
        }
    }
    printf("%d", sum);
}