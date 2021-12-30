#include <stdio.h>

int paper[101][101], cnt = 0;

void func(int ii, int jj) {
    if(paper[ii][jj] == 0) return;
    if(paper[ii-1][jj] == 0) cnt = cnt + 1;
    if(paper[ii+1][jj] == 0) cnt = cnt + 1;
    if(paper[ii][jj-1] == 0) cnt = cnt + 1;
    if(paper[ii][jj+1] == 0) cnt = cnt + 1;

}

int main() {
    int n, x, y;
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
            func(i, j);
        }
    }

    printf("%d", cnt);
}