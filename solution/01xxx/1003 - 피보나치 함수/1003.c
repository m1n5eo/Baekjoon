#include <stdio.h>

int main() {
    int zero[44] = {1, 0, }, one[44] = {0, 1, };
    for(int i = 2; i <= 40; i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }

    int n, t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d %d\n", zero[n], one[n]);
    }
}
