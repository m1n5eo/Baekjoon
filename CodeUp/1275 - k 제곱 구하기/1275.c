#include <stdio.h>

int main() {
    int n, m, sum = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) sum = sum * n;
    printf("%d", sum);
}