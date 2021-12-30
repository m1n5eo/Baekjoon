#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 2100000000, sum = 2100000000;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &n);
        sum = sum < n? sum : n;
    }
    for(int i = 0; i < 2; i++) {
        scanf("%d", &n);
        if(n < a) a = n;
    }
    sum = sum + a - 50;
    printf("%d", sum);
}
