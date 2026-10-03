#include <bits/stdc++.h>
using namespace std;

int factorial(int num) {
    int rtn = 1;
    for(int i = num; i >= 2; i--) rtn *= i;
    return rtn;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", factorial(n)/(factorial(k)*factorial(n-k)));
}

