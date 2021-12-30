#include <stdio.h>

int n, sum = 0;

int plus(int num) {
    if(num == n+1) return 0;
    sum = sum + num;
    return plus(num+1);
}

int main() {
    scanf("%d", &n);
    plus(1);
    printf("%d", sum);
}