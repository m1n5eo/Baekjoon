#include <stdio.h>

int main() {
    int n, cnt = 1;
    scanf("%d", &n);
    int m = n;
    while(1) {
        m = (m%10)*10 + (m/10 + m%10)%10;
        if(n == m) break;
        else cnt += 1;
    }
    printf("%d", cnt);
}