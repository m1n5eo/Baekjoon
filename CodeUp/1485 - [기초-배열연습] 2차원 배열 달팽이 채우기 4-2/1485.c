#include <stdio.h>

int main() {
    int n, m, arr[102][102], r = 0, c = -1, sw = 1;
    scanf("%d %d", &n, &m);
    int x = n, y = m, k = n*m;

    while(n > 0 || m > 0) {
        for(int i = 0; i < m; i++) {
            c = sw + c;
            arr[r][c] = k--;
        }
        n = n - 1;
        if(0 >= k) break;
        for(int i = 0; i < n; i++) {
            r = sw + r;
            arr[r][c] = k--;
        }
        m = m - 1;
        sw = sw * -1;
     }

     for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
     }
}