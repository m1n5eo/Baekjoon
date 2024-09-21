#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, fibo[1003] = {0, 1, 2, };
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2])%10007;
    }
    printf("%d", fibo[n]);
}
