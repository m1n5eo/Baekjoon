#include <stdio.h>

int main() {
    int ch[200], i = 0, j, n, next;
    scanf("%d", &n);
    next = n;
    printf("2 ");
    if(n == 0) {
        printf("0");
        return 0;
    }
    while(n > 0) {
        ch[i] = n % 2;
        n = n / 2;
        i++;
    }
    for(j = i - 1; j >= 0; j--) printf("%d", ch[j]);
    printf("\n");

    printf("8 %o\n", next);
    printf("16 %X\n", next);
}