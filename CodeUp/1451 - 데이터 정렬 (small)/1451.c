#include <stdio.h>

int main() {
    int n, t;
    scanf("%d", &n);
    int number[n+1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(number[i] > number[j]) {
                t = number[i];
                number[i] = number[j];
                number[j] = t;
            }
        }
        printf("%d\n", number[i]);
    }
}