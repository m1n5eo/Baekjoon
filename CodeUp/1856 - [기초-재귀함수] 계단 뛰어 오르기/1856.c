#include <stdio.h>

int fibo(int num) {
    if(num == 1) return 1;
    else if(num == 2) return 2;
    else if(num == 3) return 4;
    else return fibo(num - 1) + fibo(num - 2) + fibo(num - 3);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}