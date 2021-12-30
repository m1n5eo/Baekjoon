#include <stdio.h>

int n;

int fibo(int num) {
    if(num <= 2) return 1;
    return fibo(num-1) + fibo(num-2);
}

int main() {
    scanf("%d", &n);
    printf("%d", fibo(n));
}