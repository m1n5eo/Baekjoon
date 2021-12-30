#include <stdio.h>

int main() {
    int n, arr[102][102], r = -1, c = 0, sw = 1, k = 1;
    scanf("%d", &n);
    int x = n;

    while(n > 0) {
        for(int i = 0; i < n; i++) {
            r = sw + r;
            arr[r][c] = k++;
        }
        n = n - 1;
        if(x * x < k) break;
        for(int i = 0; i < n; i++) {
            c = sw + c;
            arr[r][c] = k++;
        }
        sw = sw * -1;
     }

     for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
     }
}