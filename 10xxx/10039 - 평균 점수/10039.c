#include <stdio.h>

int main() {
    int n = 5, num, sum = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &num);

        if(num < 40) num = 40;
        sum += num;
    }

    printf("%d", sum/n);
}