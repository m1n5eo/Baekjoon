#include <stdio.h>

int main() {
    int jr[10][10], x, y, cnt = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            scanf("%d", &jr[i][j]);
        }
    }
    scanf("%d %d", &x, &y);
    if(jr[x][y] == 1) {
        printf("-1");
        return 0;
    }
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            if((x != i || y != j) && jr[i][j] == 1) {
                cnt = cnt + 1;
            }
        }
    }
    if(cnt == 0) printf("0");
    else if(cnt != 0) printf("%d", cnt);
}