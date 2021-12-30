#include <stdio.h>

void change(int num) {
    if(num == 0) return;
    change(num/2);
    printf("%d", num%2);
}

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) printf("0");
    else change(n);
}