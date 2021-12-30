#include <stdio.h>

int pan[7][7], cnt = 0, dap = 0, check;

void f(int n, int m) {
    if(n < 0 || m < 0 || n >= 7 || m >= 7) return;
    else if(pan[n][m] != check) return;
    pan[n][m] = 0;
    cnt = cnt + 1;
    f(n-1, m);
    f(n+1, m);
    f(n, m-1);
    f(n, m+1);
}

int main() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            scanf("%d", &pan[i][j]);
        }
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(pan[i][j] != 0) {
                check = pan[i][j];
                f(i, j);
                if(cnt > 2) dap = dap + 1;
                cnt = 0;
            }
        }
    }
    printf("%d", dap);
}