#include <stdio.h>

int n, k;
long long int sum = 1;

long long int f(int num, int kk) {
    if(kk == k+1) return 1;
    else {
        sum = sum * num;
        return f(num, kk+1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    f(n, 1);
    printf("%lld", sum);
}