#include <stdio.h>

int n;
long long int dap;

void f(int num) {
    if(num == 0) return;
    dap = dap*10 + num%10;
    return f(num/10);
}


int main() {
    scanf("%d", &n);
    f(n);
    printf("%lld", dap);
}