#include <stdio.h>
#include <algorithm>

using namespace std;

int size, map[25][25], cnt[555], a = 0;

void dfs(int n, int m) {
    if(n < 0 || m < 0 || n >= size || m >= size) return;
    else if(!map[n][m]) return;
    map[n][m] = 0;
    cnt[a] = cnt[a] + 1;
    dfs(n-1, m);
    dfs(n+1, m);
    dfs(n, m-1);
    dfs(n, m+1);
}

int main() {
    scanf("%d", &size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(map[i][j]) {
                dfs(i, j);
                a = a + 1;
            }
        }
    }
    printf("%d\n", a);
    sort(cnt, cnt+a);
    for(int i = 0; i < a; i++) printf("%d\n", cnt[i]);
}