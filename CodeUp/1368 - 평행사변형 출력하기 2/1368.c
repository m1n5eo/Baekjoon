#include <stdio.h>

int main() {
    int h, k;
    char d;
    scanf("%d %d %c", &h, &k, &d);

    if(d == 'L') {
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j < i; j++) printf(" ");
            for(int j = 1; j <= k; j++) printf("*");
            printf("\n");
        }
    }
    else if(d == 'R') {
        for(int i = h; i >= 1; i--) {
            for(int j = 1; j < i; j++) printf(" ");
            for(int j = 1; j <= k; j++) printf("*");
            printf("\n");
        }
    }
}