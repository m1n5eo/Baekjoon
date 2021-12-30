#include <stdio.h>

int n, m, k, p;
int baechu[53][53]; /// xam ybn

void f(int x, int y) {
    if(x < 0 || x >= m || y < 0 || y >= n) return;
    if(!(baechu[x][y] == 1)) return;
    else baechu[x][y] = p;
    f(x+1, y);
    f(x, y+1);
    f(x-1, y);
    f(x, y-1);
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d %d %d", &m, &n, &k);
        p = 2;
        for(int i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            baechu[a][b] = 1;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(baechu[i][j] == 1) {
                    f(i, j);
                    p = p+1;
                }
            }
        }
        printf("%d\n", p-2);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                baechu[i][j] = 0;
            }
        }
    }
}