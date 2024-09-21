#include <bits/stdc++.h>
using namespace std;

long long int func(long long int a, long long int b, long long int c) {
    // printf("func(%lld, %lld, %lld)\n", a, b, c);
    if(b == 1) return a;
    long long int k = func(a, b/2, c)%c;
    if(b%2 == 1) return ((k*k)%c*a)%c;
    else if(b%2 == 0) return (k*k)%c;
}

int main() {
    long long int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", func(a, b, c)%c);
}