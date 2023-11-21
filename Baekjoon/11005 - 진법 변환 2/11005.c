#include <stdio.h>
#include <string.h>

int main() {
    int n, b, cnt = 0;
    long long int temp = 1;
    scanf("%d %d", &n, &b);
    while(1) {
        if(temp*b <= n) {
            temp *=b;
            cnt++;
        }
        else break;
    }

    for(int i = 0; i < cnt+1; i++) {
        for(int j = b-1; j >= 0; j--) {
            if(temp*j <= n) {
                if(0 <= j && j <= 9) printf("%d", j);
                else printf("%c", j+55);
                n -= temp*j;
                temp /= b;
                break;
            }
        }
    }
}