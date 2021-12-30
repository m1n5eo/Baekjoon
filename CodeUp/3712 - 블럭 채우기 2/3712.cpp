#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 1;
    scanf("%d", &n);
    if(n % 3 != 0) {
        printf("0");
        return 0;
    }
    for(int i = 1; i <= n/3; i++) {
        sum = (sum * 2) % 100000007;
    }
    printf("%d", sum);
}