#include <bits/stdc++.h>
using namespace std;

int cal(int num) {
    if(num == 0) return 0;
    return cal(num/10) + num%10;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        if(cal(i)+i == n) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}
