#include <stdio.h>

int main() {
    int n[4], m[4], max = 0;
    for(int i = 1; i <= 3; i++) scanf("%d %d", &n[i], &m[i]);

    for(int i = 1; i <= 3; i++) {
        if(max < n[i] * m[i]) max = n[i] * m[i];
    }
    printf("%d", max);
}