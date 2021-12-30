#include <stdio.h>

int main() {
    int n;
    long long int dap = 1;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        dap = dap * 2;
    }
    printf("%lld", dap-1);
}