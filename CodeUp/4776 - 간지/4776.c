#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    printf("%c", ((year+8)%12)+65);
    printf("%d", (year+6)%10);
}