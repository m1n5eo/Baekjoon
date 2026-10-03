#include <stdio.h>

int main() {
    int h, w, n, t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d %d %d", &h, &w, &n);

        if(n%h == 0) printf("%d", h);
        else printf("%d", n%h);

        if(((n-1)/h+1)/10 == 0) printf("0");
        printf("%d\n", (n-1)/h+1);
    }
}
