#include <stdio.h>

int main()
{
    int n, sum = 0;
    for(int i = 1; i <= 7; i++) {
        scanf ("%d", &n);
        if(n % 2 == 1) {
            sum = sum + n;
        }
    }
    if(sum == 0) {
        printf("-1");
        return 0;
    }
    else printf("%d", sum);
    return 0;
}