#include <stdio.h>

int paper[101][101];

int main() {
    int n, x, y, cnt = 0;
    scanf("%d", &n);
    for(int testcase = 0; testcase < n; testcase++) {
        scanf("%d %d", &x, &y);
        for(int i = x; i <= x+9; i++) {
            for(int j = y; j <= y+9; j++) {
                paper[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(paper[i][j] == 1) cnt = cnt + 1;
        }
    }

    printf("%d", cnt);
}