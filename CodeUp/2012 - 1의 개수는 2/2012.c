#include <stdio.h>

int f(int n) {
    if(n == 0) return 0;
    else if(n % 10 == 1) return f(n/10) + 1;
    return f(n/10);
}

int main() {
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = n; i <= m; i++) {
        cnt = cnt + f(i);
    }
    printf("%d", cnt);
}