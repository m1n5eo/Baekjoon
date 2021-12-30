#include <stdio.h>

int main() {
    int num[8], sum = 0, min = 111;
    for(int i = 1; i <= 7; i++) scanf("%d", &num[i]);
    for(int i = 1; i <= 7; i++) {
        if(num[i] % 2 != 0) {
            sum = sum + num[i];
            if(min > num[i]) min = num[i];
        }
    }
    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}