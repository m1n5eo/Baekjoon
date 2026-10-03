#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, m = 1, i = 1;
    scanf("%lld", &n);
    while(1) {
        if(m >= n) break;
        i = i+1;
        m = m+i;
    }
    if(n == m) i+=1;
    printf("%lld", i-1);
}
