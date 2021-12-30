#include <stdio.h>

int w, h;
char map[100][100];

void f(int n, int m) {
    if(n < 0 || m < 0 || n >= h || m >= w) return;
    if(map[n][m] == '.') return;
    map[n][m] = '.';
    f(n-1, m);
    f(n-1, m-1);
    f(n, m-1);
    f(n+1, m-1);
    f(n+1, m);
    f(n+1, m+1);
    f(n, m+1);
    f(n-1, m+1);
}

int main() {
    int i, j, cnt = 0;
    scanf("%d %d", &w, &h);
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            if(map[i][j] == 'L') {
                f(i, j);
                cnt = cnt + 1;
            }
        }
    }
    printf("%d\n", cnt);
}