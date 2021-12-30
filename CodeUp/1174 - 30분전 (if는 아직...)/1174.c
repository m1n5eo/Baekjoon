#include <stdio.h>

int main() {
    int sum, h, m;
    scanf("%d %d", &h, &m);
    sum = ( h*60 + m ) - 30;
    for (int i = 0; i < 1 && h == 0; i++) sum = 24*60 + sum;
    for (int i = 0; i < 1 && sum / 60 == 24 && sum % 60 == 0; i++) {
        printf("0 0");
        return 0;
    }
    printf("%d %d", sum / 60, sum % 60);
}