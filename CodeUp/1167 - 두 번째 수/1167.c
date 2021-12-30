#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b && b < c && a < c)// 1 2 3
        printf("%d", b);
    else if (a < b && b > c && a < c)// 1 3 2
        printf("%d", c);
    else if (a > b && b < c && a < c)// 2 1 3
        printf("%d", a);
    else if (a < b && b > c && a > c)// 2 3 1
        printf("%d", a);
    else if (a > b && b < c && a > c)// 3 1 2
        printf("%d", c);
    else if (a > b && b > c && a > c)// 3 2 1
        printf("%d", b);
    else if (a == b && b < c && a < c)//1 1 2
        printf("%d", b);
    else if (a < b && b > c && a == c)//1 2 1
        printf("%d", a);
    else if (a > b && b == c && a > c)//2 1 1
        printf("%d", b);
    else // 1 1 1
        printf("%d", a);
    return 0;
}