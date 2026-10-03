#include <stdio.h>

int main() {
    int n, arr[111];
    scanf("%d", &n);
    for(int i = 1; ; i*=2) {
        if(n < i) {
            printf("%d", i/2);
            break;
        }
    }
}