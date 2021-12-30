#include <stdio.h>

int main() {
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    for(int i = n; i <= m; i++) {
        if(i % 2 == 0) sum = sum - i;
        else if(i % 2 != 0) sum = sum + i;
    }
    printf("%d", sum);
}