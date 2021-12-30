#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, k, g = 0, first_x, first_y, second_x, second_y;
int cnt[999], pan[100][100];

void f(int a, int b) {
    if(a < 0 || b < 0 || a >= n || b >= m) return;
    else if(pan[a][b] == 1) return;
    pan[a][b] = 1;
    cnt[g] = cnt[g] + 1;
    f(a-1, b);
    f(a+1, b);
    f(a, b-1);
    f(a, b+1);
}

int main() {
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &first_x, &first_y, &second_x, &second_y);
        for(int x = first_x; x < second_x; x++) {
            for(int y = first_y; y < second_y; y++) {
                pan[x][y] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!pan[i][j]) {
                f(i, j);
                g = g + 1;
            }
        }
    }
    printf("%d\n", g);
    sort(cnt, cnt+g);
    for(int i = 0; i < g; i++) printf("%d ", cnt[i]);
}