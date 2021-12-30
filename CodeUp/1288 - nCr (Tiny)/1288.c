#include <stdio.h>

int main() {
    int n, r, up = 1, down = 1;
    scanf("%d %d", &n, &r);
    for(int i = 2; i <= n; i++) up = up * i;
    for(int i = 2; i <= r; i++) down = down * i;
    for(int i = 2; i <= n-r; i++) down = down * i;
    printf("%d", up/down);
}