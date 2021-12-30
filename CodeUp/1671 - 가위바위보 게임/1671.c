#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == m) printf("tie");
    else if((n == 0 && m == 1) || (n == 1 && m == 2) || (n == 2 && m == 0)) printf("win");
    else printf("lose");
}