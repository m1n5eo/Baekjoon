#include <stdio.h>

int sum = 0;
long long int n;

int f(long long int num) {
    if(num == 0) return sum + 0;
    sum = sum + num%10;
    return f(num/10);
}

int main() {
    scanf("%lld", &n);
    printf("%d", f(n));
}