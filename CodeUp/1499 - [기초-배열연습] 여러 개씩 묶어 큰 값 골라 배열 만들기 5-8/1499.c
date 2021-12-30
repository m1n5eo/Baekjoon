#include <stdio.h>

int main() {
    int n, g, num, max = -777777;
    scanf("%d %d", &n, &g);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(i % g == 0 && i != 0) {
            printf("%d ", max);
            max = -77777;
        }
        if(max < num) {
            max = num;
        }
    }
    printf("%d", max);
}