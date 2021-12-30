#include <stdio.h>

int main() {
    int a, b, ondo, dap[11] = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2, 1};
    scanf("%d %d", &a, &b);
    if (a - b > 0) ondo = a - b;
    else ondo = b - a;
    printf("%d", ondo/10+dap[ondo%10]);
}