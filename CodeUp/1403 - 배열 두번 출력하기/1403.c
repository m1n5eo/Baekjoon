#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num[n+1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n*2; i++) {
        printf("%d\n", num[i%n]);
    }
}