#include <stdio.h>

int main() {
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);

    if(n % 2 == 0) {
        sum = -n;
        printf("-%d", n);
    }
    else if(n % 2 != 0) {
        sum = n;
        printf("%d", n);
    }

    for(int i = n+1; i <= m; i++) {
        if(i % 2 == 0) {
            sum = sum - i;
            printf("-%d", i);
    }
        else if(i % 2 != 0) {
            sum = sum + i;
            printf("+%d", i);
        }
    }

    if(sum > 0) printf("=+%d", sum);
    else if(sum < 0) printf("=%d", sum);
    else printf("%d", sum);
}