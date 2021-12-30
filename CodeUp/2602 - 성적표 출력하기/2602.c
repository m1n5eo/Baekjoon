#include <stdio.h>

int main() {
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    scanf("%d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3);
    printf("%d %d %d %d \n%d %d %d %d \n%d %d %d %d \n%d %d %d %d ", a1, a2, a3, a1+a2+a3, b1, b2, b3, b1+b2+b3, c1, c2, c3, c1+c2+c3, a1+b1+c1, a2+b2+c2, a3+b3+c3, a1+a2+a3+b1+b2+b3+c1+c2+c3);
}