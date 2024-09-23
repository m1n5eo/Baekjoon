#include <stdio.h>

int main() {
    int n, cal[6] = {1, 1, 2, 2, 2, 8};

    for(int i = 0; i < 6; i++) {
        scanf("%d", &n);
        printf("%d ", cal[i]-n);
    }
}