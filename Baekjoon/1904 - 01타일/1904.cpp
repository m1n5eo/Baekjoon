#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, fibo1 = 1, fibo2 = 2, fibo3;
    scanf("%d", &n);
    if(n == 1) {
        printf("%d", fibo1);
        return 0;
    }
    else if(n == 2) {
        printf("%d", fibo2);
        return 0;
    }
    for(int i = 3; i <= n; i++) {
        fibo3 = (fibo2 + fibo1)%15746;
        fibo1 = fibo2;
        fibo2 = fibo3;
    }
    printf("%d", fibo3);
}
