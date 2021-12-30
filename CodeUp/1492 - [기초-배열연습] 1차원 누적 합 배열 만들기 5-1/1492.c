#include <stdio.h>

int main() {
    int n, su, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &su);
        sum = sum + su;
        printf("%d ", sum);
    }
}