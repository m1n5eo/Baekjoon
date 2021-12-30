#include <stdio.h>

int main() {
    int n, m, wait, arr[1002][1002], c = 0, sw = -1, k = 1;
    scanf("%d %d %d", &n, &m, &wait);
    int x = m, y = n, r = m;

    while(n > 0 && m > 0) {
        for(int i = 0; i < m; i++) {
            r = sw + r;
            arr[r][c] = k++;
        }
        sw = sw * -1;
        n = n - 1;
        for(int i = 0; i < n; i++) {
            c = sw + c;
            arr[r][c] = k++;
        }
        m = m - 1;
     }

     for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(arr[i][j] == wait) {
                printf("%d %d", j+1, x-i);
                return 0;
            }
        }
     }
     printf("0");
}