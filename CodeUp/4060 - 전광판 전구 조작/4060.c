#include <stdio.h>

int n, m, pan[100][100], copy[100][100];

void ff(int a, int b) {
    if(a < 0 || b < 0 || a >= n || b >= m) return;
    else if(pan[a][b] == 1) return;
    pan[a][b] = 1;
    ff(a-1, b);
    ff(a+1, b);
    ff(a, b-1);
    ff(a, b+1);
}

void f(int a, int b) {
    if(a < 0 || b < 0 || a >= n || b >= m) return;
    else if(copy[a][b] == 0) return;
    copy[a][b] = 0;
    f(a-1, b);
    f(a+1, b);
    f(a, b-1);
    f(a, b+1);
}

int main() {
    int cnt = 0;
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &pan[i][j]);
            copy[i][j] = pan[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(pan[i][j] == 0) {
                ff(i, j);
                cnt = cnt + 1;
            }
        }
    }
    printf("%d ", cnt);
    cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(copy[i][j] == 1) {
                f(i, j);
                cnt = cnt + 1;
            }
        }
    }
    printf("%d", cnt);
}