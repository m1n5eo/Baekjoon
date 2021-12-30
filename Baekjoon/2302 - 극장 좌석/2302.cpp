#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k = 0, dap = 1, jari, fibo[41] = {1, 1, };
    for(int i = 2; i <= 40; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &jari);
        dap = dap * fibo[jari-k-1];
        k = jari;
    }
    dap = dap * fibo[n-k];
    printf("%d", dap);
}
