#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i = 1, g = 9;
    long long int sum = 0;
    scanf("%d", &n);
    while(1) {
        if(g < n) {
            sum += i*g;
            i++;
            n = n-g;
            g = g*10;
        }
        else if(g >= n) {
            sum += i*n;
            break;
        }
    }
    printf("%lld", sum);
}
