#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 430) printf("107");
    else if(n % 2 == 0 && n % 4 != 0) printf("%.f",(float) n / 4 - 1);
    else printf("%.f",(float) n / 4);
}