#include <stdio.h>

int main() {
    int i, n, sum = 0;
    int apple[102], school[102];
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        scanf ("%d %d", &school[i], &apple[i]);
        sum = sum + (apple[i] % school[i]);
    }
    printf ("%d", sum);
    return 0;
}