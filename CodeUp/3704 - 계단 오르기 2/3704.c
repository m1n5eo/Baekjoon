#include <stdio.h>

int fibo[100003] = {1, 1, 2,};

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 3; i <= n; i++) fibo[i] = (fibo[i-1] + fibo[i-2] + fibo[i-3]) % 1000;

    printf("%d", fibo[n]);
}