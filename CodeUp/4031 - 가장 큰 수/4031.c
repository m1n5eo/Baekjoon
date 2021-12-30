#include <stdio.h>

int main() {
    int num, odd = 0, even = 0;
    for(int i = 0; i < 7; i++) {
        scanf("%d", &num);
        if(num % 2 == 1 && odd < num) odd = num;
        else if(num % 2 == 0 && even < num) even = num;
    }
    printf("%d", odd+even);
}