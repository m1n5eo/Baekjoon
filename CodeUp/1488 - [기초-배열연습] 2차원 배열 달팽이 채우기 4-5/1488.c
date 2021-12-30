#include <stdio.h>

int main() {
    int n, m, arr[102][102], r = 0, c = -1, sw = 1, k = 1;
    scanf("%d %d", &n, &m);
    int x = n, y = m;

    while(n > 0 || m > 0) {
        for(int i = 0; i < m; i++) {
            c = sw + c;
            arr[r][c] = k++;
        }
        n = n - 1;
        if(x * y < k) break;
        for(int i = 0; i < n; i++) {
            r = sw + r;
            arr[r][c] = k++;
        }
        m = m - 1;
        sw = sw * -1;
     }

     for(int i = x-1; i >= 0; i--) {
        for(int j = y-1; j >= 0; j--) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
     }
}