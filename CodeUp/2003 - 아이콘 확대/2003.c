#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) printf("*");
        for(int j = 0; j < n; j++) printf("x");
        for(int j = 0; j < n; j++) printf("*");
        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) printf(" ");
        for(int j = 0; j < n*2; j++) printf("x");
        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) printf("*");
        for(int j = 0; j < n; j++) printf(" ");
        for(int j = 0; j < n; j++) printf("*");
        printf("\n");
    }
}