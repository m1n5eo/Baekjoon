#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, fibo[111] = {0, 1};
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    printf("%lld", fibo[n]);
}
