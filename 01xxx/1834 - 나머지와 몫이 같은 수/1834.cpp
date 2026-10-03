#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    long long int sum = 0;
    scanf("%lld", &n);
    for(long long int i = n+1; i <= n*n; i+=n+1) {
        sum = sum + i;
    }
    printf("%lld", sum);
}
