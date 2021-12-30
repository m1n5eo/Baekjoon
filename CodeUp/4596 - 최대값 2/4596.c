#include <stdio.h>

int main() {
    int x, y, max = -1, arr[10][10];
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] > max) {
                max = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n%d %d", max, x, y);
}