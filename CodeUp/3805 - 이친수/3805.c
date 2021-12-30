#include <stdio.h>

long long int fibo[93] = {0, 1, 1,};

int main() {
   int n;
    scanf("%d", &n);

    for(int i = 3; i <= n; i++) {
        fibo[i] = fibo[i-2] + fibo[i-1];
    }

    printf("%lld", fibo[n]);
}