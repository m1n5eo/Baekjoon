#include <stdio.h>

int main() {
    int n, sum = 0, i = 1;
    scanf("%d", &n);
    while(n > sum) {
        sum = sum + i;
        i = i + 1;
    }
    printf("%d", i-1);
}