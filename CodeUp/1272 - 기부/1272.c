#include <stdio.h>

int main() {
    int kibu[3], sum = 0;
    for(int i = 1; i <= 2; i++) {
        scanf("%d", &kibu[i]);
        if(kibu[i] % 2 != 0) sum = sum + (kibu[i] / 2 + 1);
        else if(kibu[i] % 2 == 0) sum = sum + ((kibu[i] / 2) * 10);
    }
    printf("%d", sum);
}