#include <stdio.h>

int main() {
    int n, i, j, x, y;
    scanf("%d", &n);

    for(i = 2; i < n; i++) {
        if(n % i == 0) {
            x = i;
            y = n / i;
            break;
        }
    }

    if((x == 0 && y == 0) || n == 1 || n == 2 || n == 3 || n == 997) {
        printf("wrong number");
        return 0;
    }

    for(j = 2; j*j <= y; j++) {
        if(y % j == 0) {
            printf("wrong number");
            return 0;
        }
    }
    printf("%d %d", x, y);
}