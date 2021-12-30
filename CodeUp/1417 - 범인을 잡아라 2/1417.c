#include <stdio.h>

int main() {
    int n[10], t;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &n[i]);
    }
    for(int i = 0; i < 10; i++) {
        for(int j = i; j < 10; j++) {
            if(n[i] >= n[j]) {
                t = n[i];
                n[i] = n[j];
                n[j] = t;
            }
        }
    }
    printf("%d", n[7]);
}