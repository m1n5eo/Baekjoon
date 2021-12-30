#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int s, p, n, arr[22];
    scanf("%lld %lld %lld", &s, &p, &n);
    arr[1] = s;
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i-1]*p;
    }
    printf("%lld", arr[n]);
}