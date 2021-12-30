#include <stdio.h>

int main() {
    int n, m, sum = 0, arr[102][102];
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int ii = 0; ii < i+1; ii++) {
                for(int jj = 0; jj < j+1; jj++) {
                    sum = sum + arr[ii][jj];
                }
            }
            printf("%d ", sum);
            sum = 0;
        }
        printf("\n");
    }
}