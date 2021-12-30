#include <stdio.h>

int n;
long long int memo[102] = {0, 1, 1,};

long long int fibo(int num) {
    if(memo[num]) return memo[num];
    return memo[num] = ( fibo(num-1) + fibo(num-2) )% 1000000007;
}

int main() {
    scanf("%lld", &n);
    printf("%d", fibo(n));
}