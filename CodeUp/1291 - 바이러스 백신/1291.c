#include <stdio.h>

int main() {
    int n, m, u;
    scanf("%d %d %d", &n, &m, &u);
    for(int i = n; i >= 1; i--) {
        if(n % i == 0 && m % i == 0 && u % i == 0) {
            printf("%d", i);
            return 0;
        }
    }
}