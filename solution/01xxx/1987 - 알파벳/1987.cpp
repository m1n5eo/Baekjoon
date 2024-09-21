#include <bits/stdc++.h> /// bj 1987
using namespace std;

int r, c, k, maxx = -1234567890, chk_al[222];
char board[22][22];

void f(int x, int y, int cnt) {
    if(x < 0 || x >= r || y < 0 || y >= c) return;

    //printf("%d %d %d\n", x, y, cnt);

    if(maxx < cnt) maxx = cnt;

    if(chk_al[board[x-1][y]] == 0) {
        chk_al[board[x-1][y]] = 1;
        f(x-1, y, cnt+1);
        chk_al[board[x-1][y]] = 0;
    }

    if(chk_al[board[x+1][y]] == 0) {
        chk_al[board[x+1][y]] = 1;
        f(x+1, y, cnt+1);
        chk_al[board[x+1][y]] = 0;
    }

    if(chk_al[board[x][y-1]] == 0) {
        chk_al[board[x][y-1]] = 1;
        f(x, y-1, cnt+1);
        chk_al[board[x][y-1]] = 0;
    }

    if(chk_al[board[x][y+1]] == 0) {
        chk_al[board[x][y+1]] = 1;
        f(x, y+1, cnt+1);
        chk_al[board[x][y+1]] = 0;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    chk_al[board[0][0]] = 1;
    f(0, 0, 1);
    printf("%d", maxx);
}
