#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
        for(int j = 1; j < n-i; j++) {
            printf(" ");
        }
        printf("*");
        for(int j = 0; j < i*2; j++) {
            printf(" ");
        }
        printf("*\n");
	}
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*");
        for(int j = 2; j < (n-i)*2; j++) {
            printf(" ");
        }
        printf("*\n");
	}
}