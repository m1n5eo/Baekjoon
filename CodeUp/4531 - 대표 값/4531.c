#include <stdio.h>

int main() {
    int num[6], sum = 0, temp;
    for(int i = 1; i <= 5; i++) {
        scanf("%d", &num[i]);
        sum = sum + num[i];
    }
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            if(num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    printf("%d\n%d", sum/5, num[3]);
}