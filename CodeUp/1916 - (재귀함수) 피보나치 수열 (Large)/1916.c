#include <stdio.h>

int pibo[201] = {0, 1, 1,};

int fibo(int num) {
    if(pibo[num]) return pibo[num];
    return pibo[num]=(fibo(num-1) + fibo(num-2))%10009;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}