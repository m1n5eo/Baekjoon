#include <stdio.h>

int main() {
    int n, g, num, min = 777777;
    scanf("%d %d", &n, &g);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(i % g == 0 && i != 0) {
            printf("%d ", min);
            min = 77777;
        }
        if(min > num) {
            min = num;
        }
    }
    printf("%d", min);
}