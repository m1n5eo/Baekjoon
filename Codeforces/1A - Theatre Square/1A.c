#include <stdio.h>

int main() {
    long long int n, m, a, temp;
    scanf("%lld %lld %lld", &n, &m, &a);
    printf("%lld", ((n-1)/a+1)*((m-1)/a+1));
}