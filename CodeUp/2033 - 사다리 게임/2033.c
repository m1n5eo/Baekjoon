#include <stdio.h>

int main() {
    int k, n, a[100003], b[100003], ladder;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    scanf("%d", &ladder);

    for(int i = 0; i < n; i++) {
        if(ladder == a[i]) {
            ladder = b[i];
        }
        else if(ladder == b[i]) {
            ladder = a[i];
        }
    }
    printf("%d", ladder);
}