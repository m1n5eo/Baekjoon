#include <stdio.h>

int f(int n) {
    printf("%d\n", n);
    if(n==1) return 1;
    else if (n%2==0) return f(n/2);
    else if (n % 2 == 1) return f (3*n+1);
}
int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}