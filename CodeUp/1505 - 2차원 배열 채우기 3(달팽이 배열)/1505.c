#include <stdio.h>

int main() {
    int n, m, arr[52][52], k = 1, r = 0, c = -1, sw = 1;
    scanf("%d", &n);
    m = n;

    while(n > 0) {
        for(int i = 0; i < n; i++) {
            c = sw + c;
            arr[r][c] = k++;
        }
        n = n - 1;
        for(int i = 0; i < n; i++) {
            r = sw + r;
            arr[r][c] = k++;
        }
        sw = sw * -1;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}