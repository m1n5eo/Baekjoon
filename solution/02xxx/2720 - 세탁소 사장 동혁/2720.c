#include <stdio.h>

int main() {
    int n, money;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &money);
        printf("%d ", money/25);
        money -= money/25*25;
        printf("%d ", money/10);
        money -= money/10*10;
        printf("%d ", money/5);
        money -= money/5*5;
        printf("%d\n", money);
    }
}
