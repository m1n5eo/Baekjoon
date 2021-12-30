#include <stdio.h>

int main() {
    int n, m, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d", &m);
        sum = sum + m;
    }
    m = 0;
    for(int i = 1; i <= n; i++) {
        m = m + i;
    }
    printf("%d", m - sum);
}