#include <stdio.h>

int main() {
    int n, k[11];
    for(int i = 1; i <= 10; i++) {
        scanf("%d", &k[i]);
    }
    scanf("%d", &n);
    printf("%d", k[n]);
}