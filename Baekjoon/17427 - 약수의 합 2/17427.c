#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    long long int res = 0;

    for(int i = 1; i <= n; i++) {
        res = res + (n/i)*i;
    }

    printf("%lld", res);
}