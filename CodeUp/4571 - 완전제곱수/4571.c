#include <stdio.h>

int main() {
    int n, m, dap, sum = 0, check = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i*i <= m; i++) {
        if(n <= i*i && i*i <= m) {
            if(check == 1) {
                dap = i*i;
                check = 0;
            }
            sum = sum + i*i;
        }
    }
    printf("%d\n%d", sum, dap);
}