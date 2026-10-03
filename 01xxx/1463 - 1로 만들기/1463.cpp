#include <bits/stdc++.h>
using namespace std;

int n, memo[1000003];

int f(int num) {
    if(num <= 1) {
        return 0;
    }
    if(memo[num]>0) return memo[num];

    memo[num]= f(num-1)+1;

    if(num % 3 == 0) {

            memo[num] = min(memo[num], f(num/3)+1);

    }
    if(num % 2 == 0) {

            memo[num] = min(memo[num], f(num/2)+1);

    }
    return memo[num];
}

int main() {
    scanf("%d", &n);
    printf("%d", f(n));
}
