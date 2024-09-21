#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long int two = 0, five = 0;
    scanf("%d %d", &n, &m);
    for(long long int i = 2; i <= n; i*=2) two += n/i;// printf("%d ", two);
    for(long long int i = 2; i <= m; i*=2) two -= m/i;// printf("%d ", two);
    for(long long int i = 2; i <= n-m; i*=2) two -= (n-m)/i;// printf("%d\n", two);
    for(long long int i = 5; i <= n; i*=5) five += n/i;// printf("%d ", five);
    for(long long int i = 5; i <= m; i*=5) five -= m/i;// printf("%d ", five);
    for(long long int i = 5; i <= n-m; i*=5) five -= (n-m)/i;// printf("%d\n", five);
    printf("%lld", min(two, five));
}