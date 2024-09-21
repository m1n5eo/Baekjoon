#include <stdio.h>

int main() {
    char str[1111];
    int n;
    scanf("%s %d", str, &n);
    printf("%c", str[n-1]);
}
