#include <stdio.h>

int main() {
    int n, cnt = 1;
    
    scanf("%d", &n);

    while(n >= cnt+8) {
        cnt += 8;
    }

    if(n == cnt) printf("1");
    else if(n == cnt+1 || n == cnt+7) printf("2");
    else if(n == cnt+2 || n == cnt+6) printf("3");
    else if(n == cnt+3 || n == cnt+5) printf("4");
    else if(n == cnt+4) printf("5");

    return 0;
}