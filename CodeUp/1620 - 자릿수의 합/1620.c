#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    while(1) {
        while(n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        n = sum;
        if(n < 10) break;
        sum = 0;
    }
    printf("%d", sum);
}