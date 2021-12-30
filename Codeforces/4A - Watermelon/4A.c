#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n == 2 || n%2 == 1) printf("NO");
    else if(n%2 == 0) printf("YES");
}