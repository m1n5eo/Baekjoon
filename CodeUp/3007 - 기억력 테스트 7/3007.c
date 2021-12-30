#include <stdio.h>

int n, m, x, y, a, sum = 0, arr[1000003] = {0, };

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        arr[i] = arr[i-1] + a;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", arr[y]-arr[x-1]);
    }
}