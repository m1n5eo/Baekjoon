#include <stdio.h>

int main() {
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);
    if(n % 10 != 0) {
        printf("-1");
        return 0;
    }
    if(n >= 300) {
        a = n / 300;
        n = n - a*300;
    }
    if(n >= 60) {
        b = n / 60;
        n = n - b*60;
    }
    c = n/10;

    printf("%d %d %d", a, b, c);
}