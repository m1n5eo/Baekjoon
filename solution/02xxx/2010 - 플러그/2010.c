#include <stdio.h>

int n, temp, sum;

int main() {
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        sum += temp-1;
    }

    printf("%d", sum+1);
}