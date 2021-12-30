#include <stdio.h>

int main() {
    int n, k, temper[100002], dap = -1000000, sum = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temper[i]);
        if(i < k) sum = sum + temper[i];
    }

    for(int i = k; i < n; i++) {
        if(dap < sum) dap = sum;
        sum = sum + temper[i] - temper[i-k];
    }

    if(dap < sum) dap = sum;

    printf("%d", dap);
}